object Form_ConsuMovsMay: TForm_ConsuMovsMay
  Left = 161
  Top = 64
  Width = 815
  Height = 658
  Caption = 'Consulta Movimientos del Mayorista'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poMainFormCenter
  Scaled = False
  Visible = True
  WindowState = wsMaximized
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object page_general: TPageControl
    Left = 0
    Top = 0
    Width = 799
    Height = 620
    ActivePage = tsb_globales
    Align = alClient
    TabOrder = 0
    OnChange = page_generalChange
    object tsb_globales: TTabSheet
      Caption = 'Resumen'
      object Splitter2: TSplitter
        Left = 0
        Top = 241
        Width = 791
        Height = 3
        Cursor = crVSplit
        Align = alTop
      end
      object GroupBox2: TGroupBox
        Left = 0
        Top = 0
        Width = 791
        Height = 241
        Align = alTop
        Caption = 'Acumulados Anuales'
        TabOrder = 0
        object Splitter5: TSplitter
          Left = 2
          Top = 161
          Width = 787
          Height = 3
          Cursor = crVSplit
          Align = alBottom
        end
        object dbgrd_acumuanual: TdxDBGrid
          Left = 2
          Top = 15
          Width = 787
          Height = 146
          Bands = <
            item
            end>
          DefaultLayout = True
          HeaderPanelRowCount = 1
          KeyField = 'CODIGO'
          ShowGroupPanel = True
          ShowSummaryFooter = True
          SummaryGroups = <>
          SummarySeparator = ', '
          Align = alClient
          PopupMenu = PopupMenu1
          TabOrder = 0
          OnDblClick = dbgrd_acumuanualDblClick
          DataSource = dts_edoanu2
          Filter.Active = True
          Filter.Criteria = {00000000}
          LookAndFeel = lfUltraFlat
          OptionsBehavior = [edgoAutoSort, edgoDragScroll, edgoEnterShowEditor, edgoImmediateEditor, edgoTabThrough, edgoVertThrough]
          OptionsDB = [edgoCancelOnExit, edgoCanDelete, edgoCanInsert, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoSyncSelection, edgoUseBookmarks, edgoUseLocate]
          OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
          OnCustomDraw = dbgrd_pronostmensCustomDraw
          object dbgrd_acumuanualMAYORIS: TdxDBGridMaskColumn
            Caption = 'Cliente'
            Width = 54
            BandIndex = 0
            RowIndex = 0
            FieldName = 'CODIGO'
          end
          object dbgrd_acumuanualNOMBRE: TdxDBGridMaskColumn
            Caption = 'Nombre'
            Width = 260
            BandIndex = 0
            RowIndex = 0
            FieldName = 'NOMBRE'
          end
          object dbgrd_acumuanualSDOINI: TdxDBGridCurrencyColumn
            Alignment = taRightJustify
            Caption = 'Saldo Inicial'
            Width = 90
            BandIndex = 0
            RowIndex = 0
            FieldName = 'SDOINI'
            SummaryFooterType = cstSum
            SummaryFooterField = 'SDOINI'
            SummaryFooterFormat = '$,0.00;-$,0.00'
          end
          object dbgrd_acumuanualCOMPRAS: TdxDBGridCurrencyColumn
            Alignment = taRightJustify
            Caption = 'Compras'
            Width = 90
            BandIndex = 0
            RowIndex = 0
            FieldName = 'CARGOS'
            SummaryFooterType = cstSum
            SummaryFooterField = 'CARGOS'
            SummaryFooterFormat = '$,0.00;-$,0.00'
          end
          object dbgrd_acumuanualABONOS: TdxDBGridCurrencyColumn
            Alignment = taRightJustify
            Caption = 'Pagos'
            Width = 90
            BandIndex = 0
            RowIndex = 0
            FieldName = 'ABONOS'
            SummaryFooterType = cstSum
            SummaryFooterField = 'ABONOS'
            SummaryFooterFormat = '$,0.00;-$,0.00'
          end
          object dbgrd_acumuanualCOMPAGOS: TdxDBGridCurrencyColumn
            Alignment = taRightJustify
            Caption = 'Compras - Pagos'
            Width = 90
            BandIndex = 0
            RowIndex = 0
            FieldName = 'NETO'
            SummaryFooterType = cstSum
            SummaryFooterField = 'NETO'
            SummaryFooterFormat = '$,0.00;-$,0.00'
          end
          object dbgrd_acumuanualSALDO: TdxDBGridCurrencyColumn
            Alignment = taRightJustify
            Caption = 'Adeudo Actual'
            Width = 90
            BandIndex = 0
            RowIndex = 0
            FieldName = 'SALDO'
            SummaryFooterType = cstSum
            SummaryFooterField = 'SALDO'
            SummaryFooterFormat = '$,0.00;-$,0.00'
          end
          object dbgrd_acumuanualTIPO: TdxDBGridMaskColumn
            Caption = 'Tipo'
            Sorted = csUp
            Visible = False
            BandIndex = 0
            RowIndex = 0
            FieldName = 'descri'
            GroupIndex = 0
          end
        end
        object GroupBox5: TGroupBox
          Left = 2
          Top = 164
          Width = 787
          Height = 75
          Align = alBottom
          Caption = 'Pendientes de Pago'
          TabOrder = 1
          object sgrd_pendpag: TAdvStringGrid
            Left = 2
            Top = 15
            Width = 783
            Height = 58
            Align = alClient
            ColCount = 5
            DefaultRowHeight = 21
            FixedCols = 0
            RowCount = 5
            FixedRows = 1
            Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goColSizing, goColMoving]
            TabOrder = 0
            Bands.Active = False
            Bands.PrimaryColor = clInfoBk
            Bands.PrimaryLength = 1
            Bands.SecondaryColor = clWindow
            Bands.SecondaryLength = 1
            Bands.Print = False
            AutoNumAlign = True
            AutoSize = False
            VAlignment = vtaTop
            EnhTextSize = False
            EnhRowColMove = False
            SortFixedCols = False
            SortNormalCellsOnly = False
            SizeWithForm = False
            Multilinecells = False
            SortDirection = sdAscending
            SortFull = True
            SortAutoFormat = True
            SortShow = False
            SortIndexShow = False
            EnableGraphics = False
            EnableHTML = True
            EnableWheel = True
            Flat = False
            SortColumn = 0
            HintColor = clYellow
            SelectionColor = clHighlight
            SelectionTextColor = clHighlightText
            SelectionRectangle = False
            SelectionRTFKeep = False
            HintShowCells = False
            HintShowLargeText = False
            OleAcceptFiles = True
            OleAcceptText = True
            PrintSettings.FooterSize = 0
            PrintSettings.HeaderSize = 0
            PrintSettings.Time = ppNone
            PrintSettings.Date = ppNone
            PrintSettings.DateFormat = 'dd/mm/yyyy'
            PrintSettings.PageNr = ppNone
            PrintSettings.Title = ppNone
            PrintSettings.Font.Charset = DEFAULT_CHARSET
            PrintSettings.Font.Color = clWindowText
            PrintSettings.Font.Height = -11
            PrintSettings.Font.Name = 'MS Sans Serif'
            PrintSettings.Font.Style = []
            PrintSettings.HeaderFont.Charset = DEFAULT_CHARSET
            PrintSettings.HeaderFont.Color = clWindowText
            PrintSettings.HeaderFont.Height = -11
            PrintSettings.HeaderFont.Name = 'MS Sans Serif'
            PrintSettings.HeaderFont.Style = []
            PrintSettings.FooterFont.Charset = DEFAULT_CHARSET
            PrintSettings.FooterFont.Color = clWindowText
            PrintSettings.FooterFont.Height = -11
            PrintSettings.FooterFont.Name = 'MS Sans Serif'
            PrintSettings.FooterFont.Style = []
            PrintSettings.Borders = pbNoborder
            PrintSettings.BorderStyle = psSolid
            PrintSettings.Centered = False
            PrintSettings.RepeatFixedRows = False
            PrintSettings.RepeatFixedCols = False
            PrintSettings.LeftSize = 0
            PrintSettings.RightSize = 0
            PrintSettings.ColumnSpacing = 0
            PrintSettings.RowSpacing = 0
            PrintSettings.TitleSpacing = 0
            PrintSettings.Orientation = poPortrait
            PrintSettings.FixedWidth = 0
            PrintSettings.FixedHeight = 0
            PrintSettings.UseFixedHeight = False
            PrintSettings.UseFixedWidth = False
            PrintSettings.FitToPage = fpNever
            PrintSettings.PageNumSep = '/'
            PrintSettings.NoAutoSize = False
            PrintSettings.PrintGraphics = False
            HTMLSettings.Width = 100
            Navigation.AllowInsertRow = False
            Navigation.AllowDeleteRow = False
            Navigation.AdvanceOnEnter = False
            Navigation.AdvanceInsert = False
            Navigation.AutoGotoWhenSorted = False
            Navigation.AutoGotoIncremental = False
            Navigation.AutoComboDropSize = False
            Navigation.AdvanceDirection = adLeftRight
            Navigation.AllowClipboardShortCuts = False
            Navigation.AllowSmartClipboard = False
            Navigation.AllowRTFClipboard = False
            Navigation.AllowClipboardAlways = False
            Navigation.AllowClipboardRowGrow = True
            Navigation.AllowClipboardColGrow = True
            Navigation.AdvanceAuto = False
            Navigation.InsertPosition = pInsertBefore
            Navigation.CursorWalkEditor = False
            Navigation.MoveRowOnSort = False
            Navigation.ImproveMaskSel = False
            Navigation.AlwaysEdit = False
            Navigation.CopyHTMLTagsToClipboard = True
            Navigation.LineFeedOnEnter = False
            ColumnSize.Save = False
            ColumnSize.Stretch = True
            ColumnSize.Location = clRegistry
            CellNode.Color = clSilver
            CellNode.NodeType = cnFlat
            CellNode.NodeColor = clBlack
            SizeWhileTyping.Height = False
            SizeWhileTyping.Width = False
            MaxEditLength = 0
            MouseActions.AllSelect = False
            MouseActions.ColSelect = False
            MouseActions.RowSelect = False
            MouseActions.DirectEdit = False
            MouseActions.DirectComboDrop = False
            MouseActions.DisjunctRowSelect = False
            MouseActions.AllColumnSize = False
            MouseActions.AllRowSize = False
            MouseActions.CaretPositioning = False
            IntelliPan = ipVertical
            URLColor = clBlue
            URLShow = False
            URLFull = False
            URLEdit = False
            ScrollType = ssNormal
            ScrollColor = clNone
            ScrollWidth = 17
            ScrollSynch = False
            ScrollProportional = False
            ScrollHints = shNone
            OemConvert = False
            FixedFooters = 0
            FixedRightCols = 0
            FixedColWidth = 64
            FixedRowHeight = 21
            FixedFont.Charset = DEFAULT_CHARSET
            FixedFont.Color = clWindowText
            FixedFont.Height = -11
            FixedFont.Name = 'MS Sans Serif'
            FixedFont.Style = []
            FixedAsButtons = False
            FloatFormat = '%.2f'
            WordWrap = False
            Lookup = False
            LookupCaseSensitive = False
            LookupHistory = False
            BackGround.Top = 0
            BackGround.Left = 0
            BackGround.Display = bdTile
            BackGround.Cells = bcNormal
            Filter = <>
            ColWidths = (
              64
              14
              14
              14
              651)
            RowHeights = (
              21
              21
              21
              21
              21)
          end
        end
      end
      object page_global: TPageControl
        Left = 0
        Top = 244
        Width = 791
        Height = 348
        ActivePage = tbs_pronosticos
        Align = alClient
        TabOrder = 1
        OnChange = page_globalChange
        object tbs_pronosticos: TTabSheet
          Caption = 'Pron�sticos'
          object GroupBox1: TGroupBox
            Left = 0
            Top = 0
            Width = 783
            Height = 320
            Align = alClient
            TabOrder = 0
            object Splitter3: TSplitter
              Left = 2
              Top = 161
              Width = 779
              Height = 3
              Cursor = crVSplit
              Align = alTop
            end
            object dbgrd_pronostmens: TdxDBGrid
              Left = 2
              Top = 47
              Width = 779
              Height = 114
              Bands = <
                item
                end>
              DefaultLayout = True
              HeaderPanelRowCount = 1
              KeyField = 'MAYORIS'
              ShowSummaryFooter = True
              SummaryGroups = <>
              SummarySeparator = ', '
              Align = alTop
              PopupMenu = PopupMenu1
              TabOrder = 1
              DataSource = dts_pronost
              Filter.Criteria = {00000000}
              LookAndFeel = lfUltraFlat
              OptionsBehavior = [edgoAutoSort, edgoDragScroll, edgoEnterShowEditor, edgoImmediateEditor, edgoTabThrough, edgoVertThrough]
              OptionsDB = [edgoCancelOnExit, edgoCanDelete, edgoCanInsert, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoSyncSelection, edgoUseBookmarks]
              OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
              OnCustomDraw = dbgrd_pronostmensCustomDraw
              object dxDBGridMaskColumn11: TdxDBGridMaskColumn
                Caption = 'Cliente'
                Width = 44
                BandIndex = 0
                RowIndex = 0
                HeaderMaxLineCount = 2
                FieldName = 'MAYORIS'
              end
              object dxDBGridMaskColumn13: TdxDBGridCurrencyColumn
                Alignment = taRightJustify
                Caption = 'Venc.>30 D�as'
                Width = 73
                BandIndex = 0
                RowIndex = 0
                HeaderMaxLineCount = 2
                FieldName = 'ANTVENC'
                SummaryFooterType = cstSum
                SummaryFooterField = 'ANTVENC'
                SummaryFooterFormat = '$,0.00;-$,0.00'
              end
              object dxDBGridDateColumn2: TdxDBGridCurrencyColumn
                Alignment = taRightJustify
                Caption = 'Venc. 1- 30 '
                Width = 71
                BandIndex = 0
                RowIndex = 0
                HeaderMaxLineCount = 2
                FieldName = 'NVOVENC'
                SummaryFooterType = cstSum
                SummaryFooterField = 'NVOVENC'
                SummaryFooterFormat = '$,0.00;-$,0.00'
              end
              object dbgrd_pronostmensColumn6: TdxDBGridCurrencyColumn
                Alignment = taRightJustify
                Caption = 'Vencido Total'
                Width = 54
                BandIndex = 0
                RowIndex = 0
                HeaderMaxLineCount = 2
                FieldName = 'VENCTOT'
                SummaryFooterType = cstSum
                SummaryFooterField = 'VENCTOT'
                SummaryFooterFormat = '$,0.00;-$,0.00'
              end
              object dbgrd_pronostmensColumn7: TdxDBGridCurrencyColumn
                Alignment = taRightJustify
                Caption = 'X Vencer en 30 d�as'
                Width = 97
                BandIndex = 0
                RowIndex = 0
                HeaderMaxLineCount = 2
                FieldName = 'PORVENC'
                SummaryFooterType = cstSum
                SummaryFooterField = 'PORVENC'
                SummaryFooterFormat = '$,0.00;-$,0.00'
              end
              object dbgrd_pronostmensColumn12: TdxDBGridCurrencyColumn
                Alignment = taRightJustify
                Caption = 'Exigible'
                Width = 56
                BandIndex = 0
                RowIndex = 0
                HeaderMaxLineCount = 2
                FieldName = 'EXIGIBLE'
                SummaryFooterType = cstSum
                SummaryFooterField = 'EXIGIBLE'
                SummaryFooterFormat = '$,0.00;-$,0.00'
              end
              object dbgrd_pronostmensColumn8: TdxDBGridCurrencyColumn
                Alignment = taRightJustify
                Caption = '10%  Venc. >30 Dias'
                Width = 59
                BandIndex = 0
                RowIndex = 0
                HeaderMaxLineCount = 2
                FieldName = 'PAGOANTVEN'
                SummaryFooterType = cstSum
                SummaryFooterField = 'PAGOANTVEN'
                SummaryFooterFormat = '$,0.00;-$,0.00'
              end
              object dbgrd_pronostmensColumn13: TdxDBGridCurrencyColumn
                Caption = 'Venc. 1- 30 '
                BandIndex = 0
                RowIndex = 0
                FieldName = 'NVOVENC'
                SummaryFooterType = cstSum
                SummaryFooterField = 'NVOVENC'
                SummaryFooterFormat = '$,0.00;-$,0.00'
              end
              object dbgrd_pronostmensColumn9: TdxDBGridCurrencyColumn
                Alignment = taRightJustify
                Caption = '67% x Vencer'
                Width = 55
                BandIndex = 0
                RowIndex = 0
                HeaderMaxLineCount = 2
                FieldName = 'PAGONVOVEN'
                SummaryFooterType = cstSum
                SummaryFooterField = 'PAGONVOVEN'
                SummaryFooterFormat = '$,0.00;-$,0.00'
              end
              object dbgrd_pronostmensColumn10: TdxDBGridCurrencyColumn
                Alignment = taRightJustify
                Caption = 'Ingresos Esperados'
                Width = 75
                BandIndex = 0
                RowIndex = 0
                HeaderMaxLineCount = 2
                FieldName = 'ABONOESP'
                SummaryFooterType = cstSum
                SummaryFooterField = 'ABONOESP'
                SummaryFooterFormat = '$,0.00;-$,0.00'
              end
              object dxDBGridMaskColumn14: TdxDBGridCurrencyColumn
                Alignment = taRightJustify
                Caption = 'Abonos'
                Width = 58
                BandIndex = 0
                RowIndex = 0
                HeaderMaxLineCount = 2
                FieldName = 'ABONOS'
                SummaryFooterType = cstSum
                SummaryFooterField = 'ABONOS'
                SummaryFooterFormat = '$,0.00;-$,0.00'
              end
              object dbgrd_pronostmensPORCENCUMPLE: TdxDBGridMaskColumn
                Alignment = taRightJustify
                Caption = '% Cumplido'
                Width = 36
                BandIndex = 0
                RowIndex = 0
                FieldName = 'PORCEN'
                SummaryFooterType = cstSum
                SummaryFooterField = 'PORGLO'
                SummaryFooterFormat = '#0.00 %'
              end
            end
            object Panel1: TPanel
              Left = 2
              Top = 15
              Width = 779
              Height = 32
              Align = alTop
              BevelOuter = bvNone
              TabOrder = 0
              object Label1: TLabel
                Left = 8
                Top = 7
                Width = 33
                Height = 20
                Caption = 'A�o'
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -16
                Font.Name = 'MS Sans Serif'
                Font.Style = [fsBold]
                ParentFont = False
              end
              object Label2: TLabel
                Left = 138
                Top = 7
                Width = 34
                Height = 20
                Caption = 'Mes'
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -16
                Font.Name = 'MS Sans Serif'
                Font.Style = [fsBold]
                ParentFont = False
              end
              object Label14: TLabel
                Left = 328
                Top = 7
                Width = 95
                Height = 20
                Caption = 'Pron�sticos'
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -16
                Font.Name = 'MS Sans Serif'
                Font.Style = [fsBold]
                ParentFont = False
              end
              object edt_anu: TdxSpinEdit
                Left = 46
                Top = 1
                Width = 89
                Hint = 'Enter = Act. Inf.'
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -16
                Font.Name = 'MS Sans Serif'
                Font.Style = [fsBold]
                ParentFont = False
                ParentShowHint = False
                ShowHint = True
                TabOrder = 0
                OnKeyDown = edt_anuKeyDown
                Value = 2005
              end
              object edt_mes: TdxSpinEdit
                Left = 175
                Top = 1
                Width = 89
                Hint = 'Enter = Actualiza Informacion'
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -16
                Font.Name = 'MS Sans Serif'
                Font.Style = [fsBold]
                ParentFont = False
                ParentShowHint = False
                ShowHint = True
                TabOrder = 1
                OnKeyDown = edt_anuKeyDown
                OnChange = edt_mesChange
                Value = 1
              end
            end
            object chart_pronosticos: TChart
              Left = 2
              Top = 164
              Width = 779
              Height = 154
              AllowPanning = pmNone
              BackWall.Brush.Color = clWhite
              BackWall.Brush.Style = bsClear
              Title.Text.Strings = (
                'TChart')
              Legend.Alignment = laBottom
              Align = alClient
              PopupMenu = PopupMenuGraf
              TabOrder = 2
              object Series1: TBarSeries
                Marks.ArrowLength = 8
                Marks.Visible = False
                SeriesColor = clRed
                VertAxis = aBothVertAxis
                SideMargins = False
                XValues.DateTime = False
                XValues.Name = 'X'
                XValues.Multiplier = 1
                XValues.Order = loAscending
                YValues.DateTime = False
                YValues.Name = 'Bar'
                YValues.Multiplier = 1
                YValues.Order = loNone
              end
              object Series2: TBarSeries
                Marks.ArrowLength = 8
                Marks.Visible = False
                SeriesColor = clGreen
                VertAxis = aBothVertAxis
                SideMargins = False
                XValues.DateTime = False
                XValues.Name = 'X'
                XValues.Multiplier = 1
                XValues.Order = loAscending
                YValues.DateTime = False
                YValues.Name = 'Bar'
                YValues.Multiplier = 1
                YValues.Order = loNone
              end
              object Series3: TBarSeries
                Marks.ArrowLength = 8
                Marks.Visible = False
                SeriesColor = clYellow
                VertAxis = aBothVertAxis
                SideMargins = False
                XValues.DateTime = False
                XValues.Name = 'X'
                XValues.Multiplier = 1
                XValues.Order = loAscending
                YValues.DateTime = False
                YValues.Name = 'Bar'
                YValues.Multiplier = 1
                YValues.Order = loNone
              end
            end
          end
        end
        object tbs_compraspagosglo: TTabSheet
          Caption = 'Acumulados'
          ImageIndex = 1
          object Splitter9: TSplitter
            Left = 249
            Top = 0
            Width = 3
            Height = 320
            Cursor = crHSplit
          end
          object dxDBGrid2: TdxDBGrid
            Left = 0
            Top = 0
            Width = 249
            Height = 320
            Bands = <
              item
              end>
            DefaultLayout = True
            HeaderPanelRowCount = 1
            KeyField = 'FECHAX'
            ShowSummaryFooter = True
            SummaryGroups = <>
            SummarySeparator = ', '
            Align = alLeft
            PopupMenu = PopupMenu1
            TabOrder = 0
            DataSource = dts_facxmesglo
            Filter.Criteria = {00000000}
            LookAndFeel = lfUltraFlat
            OptionsBehavior = [edgoDragScroll, edgoEnterShowEditor, edgoImmediateEditor, edgoTabThrough, edgoVertThrough]
            OptionsDB = [edgoCancelOnExit, edgoCanDelete, edgoCanInsert, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoSyncSelection, edgoUseBookmarks]
            OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
            OnCustomDraw = dbgrd_pronostmensCustomDraw
            object dxDBGridMaskColumn1: TdxDBGridMaskColumn
              Caption = 'A�o/Mes'
              BandIndex = 0
              RowIndex = 0
              HeaderMaxLineCount = 0
              FieldName = 'FECHAX'
              DisableFilter = True
            end
            object dxDBGridCurrencyColumn1: TdxDBGridCurrencyColumn
              Caption = 'Compras'
              Width = 67
              BandIndex = 0
              RowIndex = 0
              FieldName = 'cargos'
              SummaryFooterType = cstSum
              SummaryFooterField = 'cargos'
              SummaryFooterFormat = '$,0.00;-$,0.00'
            end
            object dxDBGrid2Column3: TdxDBGridCurrencyColumn
              Caption = 'Abonos'
              Width = 84
              BandIndex = 0
              RowIndex = 0
              FieldName = 'abonos'
              SummaryFooterType = cstSum
              SummaryFooterField = 'abonos'
              SummaryFooterFormat = '$,0.00'
            end
          end
          object chart_comprasglo: TChart
            Left = 252
            Top = 0
            Width = 531
            Height = 320
            AllowPanning = pmNone
            BackWall.Brush.Color = clWhite
            BackWall.Brush.Style = bsClear
            Title.Text.Strings = (
              'Grafica de Compras / Pagos Global')
            Legend.Alignment = laBottom
            Legend.TopPos = 9
            Align = alClient
            BevelOuter = bvNone
            PopupMenu = PopupMenuGraf
            TabOrder = 1
            object charseries_comprasglo: TBarSeries
              Marks.ArrowLength = 8
              Marks.Visible = False
              SeriesColor = clRed
              Title = 'Compras'
              VertAxis = aBothVertAxis
              SideMargins = False
              XValues.DateTime = False
              XValues.Name = 'X'
              XValues.Multiplier = 1
              XValues.Order = loAscending
              YValues.DateTime = False
              YValues.Name = 'Bar'
              YValues.Multiplier = 1
              YValues.Order = loNone
            end
            object charseries_pagosglo: TBarSeries
              Marks.ArrowLength = 8
              Marks.Visible = False
              SeriesColor = clGreen
              Title = 'Pagos'
              VertAxis = aBothVertAxis
              SideMargins = False
              XValues.DateTime = False
              XValues.Name = 'X'
              XValues.Multiplier = 1
              XValues.Order = loAscending
              YValues.DateTime = False
              YValues.Name = 'Bar'
              YValues.Multiplier = 1
              YValues.Order = loNone
            end
          end
        end
        object TabSheet1: TTabSheet
          Caption = 'Vencimientos'
          ImageIndex = 2
          object char_vencglo: TChart
            Left = 249
            Top = 0
            Width = 496
            Height = 324
            AllowPanning = pmNone
            BackWall.Brush.Color = clWhite
            BackWall.Brush.Style = bsClear
            Title.Text.Strings = (
              'Gr�fica de vencimientos Globales')
            Legend.Alignment = laBottom
            Legend.TopPos = 9
            Align = alClient
            BevelOuter = bvNone
            PopupMenu = PopupMenuGraf
            TabOrder = 0
            object bar_vencglo: TBarSeries
              HorizAxis = aBothHorizAxis
              Marks.ArrowLength = 8
              Marks.Visible = False
              SeriesColor = clRed
              ShowInLegend = False
              Title = 'Vencimientos'
              VertAxis = aBothVertAxis
              SideMargins = False
              XValues.DateTime = False
              XValues.Name = 'X'
              XValues.Multiplier = 1
              XValues.Order = loAscending
              YValues.DateTime = False
              YValues.Name = 'Bar'
              YValues.Multiplier = 1
              YValues.Order = loNone
            end
          end
          object dbgrd_vencglo: TdxDBGrid
            Left = 0
            Top = 0
            Width = 249
            Height = 324
            Bands = <
              item
              end>
            DefaultLayout = True
            HeaderPanelRowCount = 1
            KeyField = 'FECHAX'
            ShowSummaryFooter = True
            SummaryGroups = <>
            SummarySeparator = ', '
            Align = alLeft
            PopupMenu = PopupMenu1
            TabOrder = 1
            DataSource = dts_pendpagglob
            Filter.Criteria = {00000000}
            LookAndFeel = lfUltraFlat
            OptionsBehavior = [edgoDragScroll, edgoEnterShowEditor, edgoImmediateEditor, edgoTabThrough, edgoVertThrough]
            OptionsDB = [edgoCancelOnExit, edgoCanDelete, edgoCanInsert, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoSyncSelection, edgoUseBookmarks]
            OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
            OnCustomDraw = dbgrd_pronostmensCustomDraw
            object dbgrd_vencgloFECHAX: TdxDBGridMaskColumn
              Caption = 'A�o/Mes'
              BandIndex = 0
              RowIndex = 0
              HeaderMaxLineCount = 0
              FieldName = 'FECHAX'
              DisableFilter = True
            end
            object dbgrd_vencgloSALDO: TdxDBGridCurrencyColumn
              Caption = 'Saldo'
              Width = 67
              BandIndex = 0
              RowIndex = 0
              FieldName = 'SALDO'
              SummaryFooterType = cstSum
              SummaryFooterField = 'SALDO'
              SummaryFooterFormat = '$,0.00;-$,0.00'
            end
          end
        end
      end
    end
    object tbs_detmayo: TTabSheet
      Caption = 'Individual'
      ImageIndex = 1
      OnShow = tbs_detmayoShow
      object Splitter4: TSplitter
        Left = 0
        Top = 126
        Width = 791
        Height = 3
        Cursor = crVSplit
        Align = alTop
      end
      object page_movmay: TPageControl
        Left = 0
        Top = 129
        Width = 791
        Height = 463
        ActivePage = tab_MovPag
        Align = alClient
        TabOrder = 0
        OnChange = page_movmayChange
        object tab_MovPag: TTabSheet
          Caption = 'Compras'
          ImageIndex = 1
          object Panel2: TPanel
            Left = 0
            Top = 224
            Width = 783
            Height = 211
            Align = alBottom
            BevelOuter = bvNone
            TabOrder = 0
            object Splitter1: TSplitter
              Left = 451
              Top = 0
              Width = 3
              Height = 211
              Cursor = crHSplit
              Align = alRight
            end
            object GroupBox3: TGroupBox
              Left = 0
              Top = 0
              Width = 451
              Height = 211
              Align = alClient
              Caption = 'Abonos'
              TabOrder = 0
              object dbgrd_pagosafac: TdxDBGrid
                Left = 2
                Top = 15
                Width = 447
                Height = 194
                Bands = <
                  item
                  end>
                DefaultLayout = True
                HeaderPanelRowCount = 1
                KeyField = 'CONSE'
                ShowSummaryFooter = True
                SummaryGroups = <>
                SummarySeparator = ', '
                Align = alClient
                PopupMenu = PopupMenu1
                TabOrder = 0
                DataSource = dtsForPago
                Filter.Criteria = {00000000}
                LookAndFeel = lfUltraFlat
                OptionsBehavior = [edgoAutoSort, edgoDragScroll, edgoEnterShowEditor, edgoImmediateEditor, edgoTabThrough, edgoVertThrough]
                OptionsDB = [edgoCancelOnExit, edgoCanDelete, edgoCanInsert, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoSyncSelection, edgoUseBookmarks]
                OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
                OnCustomDraw = dbgrd_pronostmensCustomDraw
                object dbgrd_pagosafacMAYORIS: TdxDBGridMaskColumn
                  Visible = False
                  Width = 59
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'MAYORIS'
                end
                object dbgrd_pagosafacDOCTO: TdxDBGridMaskColumn
                  Caption = 'Docto'
                  Width = 57
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'DOCTO'
                end
                object dbgrd_pagosafacPAGARE: TdxDBGridMaskColumn
                  Alignment = taCenter
                  Caption = 'Pagare'
                  Width = 50
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'PAGARE'
                end
                object dbgrd_pagosafacCONSE: TdxDBGridMaskColumn
                  Visible = False
                  Width = 46
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'CONSE'
                end
                object dbgrd_pagosafacFECHA: TdxDBGridDateColumn
                  Caption = 'Fecha'
                  Width = 70
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'FECHA'
                end
                object dbgrd_pagosafacVENCE: TdxDBGridDateColumn
                  Visible = False
                  Width = 45
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'VENCE'
                end
                object dbgrd_pagosafacCONCEP: TdxDBGridMaskColumn
                  Caption = 'Concepto'
                  Width = 200
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'CONCEP'
                end
                object dbgrd_pagosafacCOA: TdxDBGridMaskColumn
                  Visible = False
                  Width = 30
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'COA'
                end
                object dbgrd_pagosafacIMPORTE: TdxDBGridCurrencyColumn
                  Caption = 'Importe Pago'
                  Width = 75
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'IMPORTE'
                  SummaryFooterType = cstSum
                  SummaryFooterField = 'IMPORTE'
                  SummaryFooterFormat = '#,##0.00'
                end
                object dbgrd_pagosafacSALDO: TdxDBGridCurrencyColumn
                  Visible = False
                  Width = 45
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'SALDO'
                end
                object dbgrd_pagosafacCIA: TdxDBGridMaskColumn
                  Visible = False
                  Width = 25
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'CIA'
                end
                object dbgrd_pagosafacTIPAGO: TdxDBGridMaskColumn
                  Visible = False
                  Width = 49
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'TIPAGO'
                end
                object dbgrd_pagosafacSTIPOPAGO: TdxDBGridColumn
                  Caption = 'Tipo de Pago'
                  Width = 120
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'STIPOPAGO'
                end
              end
            end
            object GroupBox11: TGroupBox
              Left = 454
              Top = 0
              Width = 329
              Height = 211
              Align = alRight
              Caption = 'Vencimientos'
              TabOrder = 1
              object dbgrd_venctosxfac: TdxDBGrid
                Left = 2
                Top = 15
                Width = 325
                Height = 194
                Bands = <
                  item
                  end>
                DefaultLayout = True
                HeaderPanelRowCount = 1
                KeyField = 'PAGARE'
                ShowGroupPanel = True
                ShowSummaryFooter = True
                SummaryGroups = <
                  item
                    DefaultGroup = True
                    SummaryItems = <
                      item
                        SummaryField = 'CARGOS'
                        SummaryFormat = '#,##0.00'
                        SummaryType = cstSum
                      end
                      item
                        SummaryField = 'ABONOS'
                        SummaryFormat = '#,##0.00'
                        SummaryType = cstSum
                      end>
                    Name = 'dxDBGrid1SummaryGroup1'
                  end>
                SummarySeparator = ', '
                Align = alClient
                TabOrder = 0
                DataSource = dtsLetras
                Filter.Criteria = {00000000}
                GroupPanelColor = 8421440
                GroupPanelFontColor = clYellow
                LookAndFeel = lfUltraFlat
                OptionsBehavior = [edgoAutoSort, edgoDragScroll, edgoEnterShowEditor, edgoImmediateEditor, edgoTabThrough, edgoVertThrough]
                OptionsDB = [edgoCancelOnExit, edgoCanDelete, edgoCanInsert, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoSyncSelection, edgoUseBookmarks]
                OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
                ShowRowFooter = True
                OnCustomDraw = dbgrd_pronostmensCustomDraw
                object dbgrd_venctosxfacMAYORIS: TdxDBGridMaskColumn
                  Visible = False
                  Width = 70
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'MAYORIS'
                end
                object dbgrd_venctosxfacDOCTO: TdxDBGridMaskColumn
                  Visible = False
                  Width = 38
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'DOCTO'
                end
                object dbgrd_venctosxfacPAGARE: TdxDBGridMaskColumn
                  Alignment = taCenter
                  Caption = 'Lta'
                  Width = 38
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'PAGARE'
                end
                object dbgrd_venctosxfacVENCE: TdxDBGridDateColumn
                  Alignment = taCenter
                  Caption = 'Vencim.'
                  Width = 73
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'VENCE'
                end
                object dbgrd_venctosxfacIMPORTE: TdxDBGridCurrencyColumn
                  Caption = 'Imp. Letra'
                  Width = 94
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'IMPORTE'
                end
                object dbgrd_venctosxfacSGRATICO: TdxDBGridImageColumn
                  Alignment = taLeftJustify
                  Caption = 'Pagado'
                  MinWidth = 16
                  Width = 50
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'SGRAFICO'
                  Descriptions.Strings = (
                    'Pago Atrasado'
                    'Pago Puntual'
                    'Atrasado')
                  Images = ImageList1
                  ImageIndexes.Strings = (
                    '0'
                    '1'
                    '2')
                  LargeImages = ImageList1
                  Values.Strings = (
                    'PATRASADO'
                    'PUNTUAL'
                    'VENCIDO')
                end
                object dbgrd_venctosxfacSFECHAPAGO: TdxDBGridMaskColumn
                  Alignment = taCenter
                  Caption = 'Fecha Pago'
                  Width = 86
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'SFECHAPAGO'
                end
              end
            end
          end
          object GroupBox12: TGroupBox
            Left = 0
            Top = 0
            Width = 783
            Height = 224
            Align = alClient
            Caption = 'Facturas'
            TabOrder = 1
            object dbgrd_analifac: TdxDBGrid
              Left = 169
              Top = 15
              Width = 612
              Height = 207
              Bands = <
                item
                end>
              DefaultLayout = True
              HeaderPanelRowCount = 1
              KeyField = 'NUM'
              ShowSummaryFooter = True
              SummaryGroups = <>
              SummarySeparator = ', '
              Align = alClient
              PopupMenu = PopupMenu1
              TabOrder = 0
              DataSource = dts_facturas
              Filter.Criteria = {00000000}
              LookAndFeel = lfUltraFlat
              OptionsBehavior = [edgoAutoSort, edgoDragScroll, edgoEnterShowEditor, edgoImmediateEditor, edgoTabThrough, edgoVertThrough]
              OptionsDB = [edgoCancelOnExit, edgoCanDelete, edgoCanInsert, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoSyncSelection, edgoUseBookmarks]
              OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
              OnCustomDraw = dbgrd_pronostmensCustomDraw
              object dbgrd_analifacTIPOFAC: TdxDBGridMaskColumn
                Caption = 'Documento'
                BandIndex = 0
                RowIndex = 0
                FieldName = 'DESCRI'
              end
              object dbgrd_analifacNUM: TdxDBGridMaskColumn
                Alignment = taCenter
                Caption = 'N�mero'
                BandIndex = 0
                RowIndex = 0
                FieldName = 'NUM'
              end
              object dbgrd_analifacFECHA: TdxDBGridDateColumn
                Caption = 'Fecha Fac'
                Width = 74
                BandIndex = 0
                RowIndex = 0
                FieldName = 'FECHA'
              end
              object dbgrd_analifacTOTAL: TdxDBGridCurrencyColumn
                Caption = 'Total Neto'
                BandIndex = 0
                RowIndex = 0
                FieldName = 'TOTAL'
                SummaryFooterType = cstSum
                SummaryFooterField = 'TOTAL'
                SummaryFooterFormat = '#,##0.00'
              end
              object dbgrd_analifacACUM: TdxDBGridCurrencyColumn
                Caption = 'Total Acumulado'
                BandIndex = 0
                RowIndex = 0
                FieldName = 'ACUM'
              end
              object dbgrd_analifacNPAGOS: TdxDBGridMaskColumn
                Alignment = taCenter
                Caption = 'Ltas.'
                Width = 38
                BandIndex = 0
                RowIndex = 0
                FieldName = 'NPAGOS'
              end
              object dbgrd_analifacPLAZO: TdxDBGridMaskColumn
                Alignment = taCenter
                Caption = 'Plazo'
                Width = 49
                BandIndex = 0
                RowIndex = 0
                FieldName = 'PLAZO'
              end
              object dbgrd_analifacSTIPAGO: TdxDBGridMaskColumn
                Caption = 'Tip Pago'
                Width = 94
                BandIndex = 0
                RowIndex = 0
                FieldName = 'STIPAGO'
              end
              object dbgrd_analifacPRIMERVENC: TdxDBGridMaskColumn
                Caption = 'Primer Vencto'
                BandIndex = 0
                RowIndex = 0
                FieldName = 'PRIMERVEN'
              end
            end
            object dbgrd_facxmes: TdxDBGrid
              Left = 2
              Top = 15
              Width = 167
              Height = 207
              Bands = <
                item
                end>
              DefaultLayout = True
              HeaderPanelRowCount = 1
              KeyField = 'FECHAX'
              ShowSummaryFooter = True
              SummaryGroups = <>
              SummarySeparator = ', '
              Align = alLeft
              PopupMenu = PopupMenu1
              TabOrder = 1
              DataSource = dts_facxmes
              Filter.Criteria = {00000000}
              LookAndFeel = lfUltraFlat
              OptionsBehavior = [edgoDragScroll, edgoEnterShowEditor, edgoImmediateEditor, edgoTabThrough, edgoVertThrough]
              OptionsDB = [edgoCancelOnExit, edgoCanDelete, edgoCanInsert, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoSyncSelection, edgoUseBookmarks]
              OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
              OnCustomDraw = dbgrd_pronostmensCustomDraw
              object dxDBGridMaskColumn8: TdxDBGridMaskColumn
                Caption = 'A�o/Mes'
                Width = 56
                BandIndex = 0
                RowIndex = 0
                HeaderMaxLineCount = 0
                FieldName = 'FECHAX'
                DisableFilter = True
              end
              object dxDBGridCurrencyColumn2: TdxDBGridCurrencyColumn
                Caption = 'Saldo'
                Width = 92
                BandIndex = 0
                RowIndex = 0
                FieldName = 'Total'
                SummaryFooterType = cstSum
                SummaryFooterField = 'total'
                SummaryFooterFormat = '$,0.00;-$,0.00'
              end
            end
          end
        end
        object tbs_pagos: TTabSheet
          Caption = 'Pagos'
          ImageIndex = 2
          object Panel3: TPanel
            Left = 0
            Top = 0
            Width = 177
            Height = 435
            Align = alLeft
            BevelOuter = bvNone
            TabOrder = 0
            object RzGroupBox5: TGroupBox
              Left = 0
              Top = 0
              Width = 177
              Height = 435
              Align = alClient
              Caption = 'Pagos x Mes'
              TabOrder = 0
              object dxDBGrid1: TdxDBGrid
                Left = 2
                Top = 15
                Width = 173
                Height = 418
                Bands = <
                  item
                  end>
                DefaultLayout = True
                HeaderPanelRowCount = 1
                KeyField = 'FECHAX'
                ShowSummaryFooter = True
                SummaryGroups = <>
                SummarySeparator = ', '
                Align = alClient
                PopupMenu = PopupMenu1
                TabOrder = 0
                DataSource = dts_abonosxmes
                Filter.Criteria = {00000000}
                LookAndFeel = lfUltraFlat
                OptionsBehavior = [edgoDragScroll, edgoEnterShowEditor, edgoImmediateEditor, edgoTabThrough, edgoVertThrough]
                OptionsDB = [edgoCancelOnExit, edgoCanDelete, edgoCanInsert, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoSyncSelection, edgoUseBookmarks]
                OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
                OnCustomDraw = dbgrd_pronostmensCustomDraw
                object dxDBGridMaskColumn12: TdxDBGridMaskColumn
                  Caption = 'A�o/Mes'
                  Width = 56
                  BandIndex = 0
                  RowIndex = 0
                  HeaderMaxLineCount = 0
                  FieldName = 'FECHAX'
                  DisableFilter = True
                end
                object dxDBGridCurrencyColumn7: TdxDBGridCurrencyColumn
                  Caption = 'Importe'
                  Width = 92
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'IMPORTE'
                  SummaryFooterType = cstSum
                  SummaryFooterField = 'IMPORTE'
                  SummaryFooterFormat = '$,0.00;-$,0.00'
                end
              end
            end
          end
          object GroupBox9: TGroupBox
            Left = 177
            Top = 0
            Width = 606
            Height = 435
            Align = alClient
            TabOrder = 1
            object Splitter8: TSplitter
              Left = 2
              Top = 212
              Width = 602
              Height = 5
              Cursor = crVSplit
              Align = alTop
            end
            object dbgrd_analipago: TdxDBGrid
              Left = 2
              Top = 217
              Width = 602
              Height = 216
              Bands = <
                item
                end>
              DefaultLayout = True
              HeaderPanelRowCount = 1
              KeyField = 'CONSE'
              ShowSummaryFooter = True
              SummaryGroups = <>
              SummarySeparator = ', '
              Align = alClient
              PopupMenu = PopupMenu1
              TabOrder = 0
              DataSource = dts_abonos
              Filter.Criteria = {00000000}
              LookAndFeel = lfFlat
              OptionsBehavior = [edgoAutoSort, edgoDragScroll, edgoEnterShowEditor, edgoImmediateEditor, edgoTabThrough, edgoVertThrough]
              OptionsDB = [edgoCancelOnExit, edgoCanDelete, edgoCanInsert, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoSyncSelection, edgoUseBookmarks]
              OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
              OnCustomDraw = dbgrd_pronostmensCustomDraw
              object dxDBGridMaskColumn2: TdxDBGridMaskColumn
                Visible = False
                Width = 62
                BandIndex = 0
                RowIndex = 0
                FieldName = 'MAYORIS'
              end
              object dxDBGridMaskColumn3: TdxDBGridMaskColumn
                Alignment = taLeftJustify
                Caption = 'Docto.'
                Width = 51
                BandIndex = 0
                RowIndex = 0
                FieldName = 'DOCTO'
              end
              object dxDBGridMaskColumn4: TdxDBGridMaskColumn
                Alignment = taCenter
                Caption = 'Pagare'
                Width = 53
                BandIndex = 0
                RowIndex = 0
                FieldName = 'PAGARE'
              end
              object dxDBGridMaskColumn5: TdxDBGridMaskColumn
                Visible = False
                Width = 72
                BandIndex = 0
                RowIndex = 0
                FieldName = 'CONSE'
              end
              object dxDBGridDateColumn1: TdxDBGridDateColumn
                Caption = 'Fecha Abono'
                Width = 87
                BandIndex = 0
                RowIndex = 0
                FieldName = 'FECHA'
              end
              object dxDBGridMaskColumn6: TdxDBGridMaskColumn
                Caption = 'Concepto'
                Width = 240
                BandIndex = 0
                RowIndex = 0
                FieldName = 'CONCEP'
              end
              object dxDBGridMaskColumn7: TdxDBGridMaskColumn
                Visible = False
                Width = 32
                BandIndex = 0
                RowIndex = 0
                FieldName = 'COA'
              end
              object dxDBGridCurrencyColumn3: TdxDBGridCurrencyColumn
                Caption = 'Importe'
                Width = 85
                BandIndex = 0
                RowIndex = 0
                FieldName = 'IMPORTE'
                SummaryFooterType = cstSum
                SummaryFooterField = 'IMPORTE'
                SummaryFooterFormat = '$,0.00;-$,0.00'
              end
              object dxDBGridMaskColumn9: TdxDBGridMaskColumn
                Caption = 'Pago'
                Width = 53
                BandIndex = 0
                RowIndex = 0
                FieldName = 'TIPAGO'
              end
              object dxDBGridMaskColumn10: TdxDBGridMaskColumn
                Visible = False
                Width = 173
                BandIndex = 0
                RowIndex = 0
                FieldName = 'SLLAVE'
              end
              object dbgrd_analipagoColumn11: TdxDBGridMaskColumn
                BandIndex = 0
                RowIndex = 0
                FieldName = 'VENCE'
              end
              object dbgrd_analipagoColumn13: TdxDBGridMaskColumn
                Caption = 'Fecha Compra'
                BandIndex = 0
                RowIndex = 0
                FieldName = 'FECFAC'
              end
              object dbgrd_analipagoColumn12: TdxDBGridMaskColumn
                Caption = 'Factura de'
                BandIndex = 0
                RowIndex = 0
                FieldName = 'STIPAGO'
              end
            end
            object GroupBox8: TGroupBox
              Left = 2
              Top = 15
              Width = 602
              Height = 197
              Align = alTop
              Caption = 'Abonos x Dia '
              TabOrder = 1
              object dbgrd_pagosxmes: TdxDBGrid
                Left = 2
                Top = 15
                Width = 598
                Height = 180
                Bands = <
                  item
                  end>
                DefaultLayout = True
                HeaderPanelRowCount = 1
                KeyField = 'FOLIO'
                ShowSummaryFooter = True
                SummaryGroups = <>
                SummarySeparator = ', '
                Align = alClient
                PopupMenu = PopupMenu1
                TabOrder = 0
                DataSource = dts_aboxtipo
                Filter.Criteria = {00000000}
                LookAndFeel = lfUltraFlat
                OptionsBehavior = [edgoAutoSort, edgoDragScroll, edgoEnterShowEditor, edgoImmediateEditor, edgoMultiSort, edgoTabThrough, edgoVertThrough]
                OptionsDB = [edgoCancelOnExit, edgoCanDelete, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoSyncSelection, edgoUseBookmarks]
                OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
                OnCustomDrawFooterNode = dbgrd_pagosxmesCustomDrawFooterNode
                OnCustomDraw = dbgrd_pronostmensCustomDraw
                object dbgrd_pagosxmesFECHA: TdxDBGridDateColumn
                  Caption = 'Fecha'
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'FECHA'
                end
                object dbgrd_pagosxmesFOLIO: TdxDBGridMaskColumn
                  Caption = 'Folio'
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'FOLIO'
                end
                object dbgrd_pagosxmesMERC: TdxDBGridCurrencyColumn
                  Caption = 'Mercancia'
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'MERC'
                  SummaryFooterType = cstSum
                  SummaryFooterField = 'merc'
                  SummaryFooterFormat = '$,0.00;-$,0.00'
                end
                object dbgrd_pagosxmesDEV: TdxDBGridCurrencyColumn
                  Caption = 'Devoluciones'
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'DEV'
                  SummaryFooterType = cstSum
                  SummaryFooterField = 'dev'
                  SummaryFooterFormat = '$,0.00;-$,0.00'
                end
                object dbgrd_pagosxmesBON: TdxDBGridCurrencyColumn
                  Caption = 'Bonificaci�n'
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'BON'
                  SummaryFooterType = cstSum
                  SummaryFooterField = 'bon'
                  SummaryFooterFormat = '$,0.00;-$,0.00'
                end
                object dbgrd_pagosxmesINT: TdxDBGridCurrencyColumn
                  Caption = 'Intereses'
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'INTERES'
                  SummaryFooterType = cstSum
                  SummaryFooterField = 'INTERES'
                  SummaryFooterFormat = '$,0.00;-$,0.00'
                end
                object dbgrd_pagosxmesMOR: TdxDBGridCurrencyColumn
                  Caption = 'Moratorios'
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'MORA'
                  SummaryFooterType = cstSum
                  SummaryFooterField = 'MORA'
                  SummaryFooterFormat = '$,0.00;-$,0.00'
                end
                object dbgrd_pagosxmesTOTAL: TdxDBGridCurrencyColumn
                  Caption = 'Total'
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'TOTAL'
                  SummaryFooterType = cstSum
                  SummaryFooterField = 'total'
                  SummaryFooterFormat = '$,0.00;-$,0.00'
                end
                object dbgrd_pagosxmesSUMAS: TdxDBGridCurrencyColumn
                  Caption = 'Pagos Acumulados'
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'ACUM'
                  SummaryFooterFormat = '$,0.00;-$,0.00'
                end
              end
            end
          end
        end
        object tab_pendpag: TTabSheet
          Caption = '&Pendientes Pago'
          object Splitter7: TSplitter
            Left = 0
            Top = 221
            Width = 783
            Height = 3
            Cursor = crVSplit
            Align = alBottom
          end
          object Panel4: TPanel
            Left = 0
            Top = 0
            Width = 783
            Height = 221
            Align = alClient
            BevelOuter = bvNone
            TabOrder = 0
            object GroupBox6: TGroupBox
              Left = 177
              Top = 0
              Width = 606
              Height = 221
              Align = alClient
              Caption = 'Facturas pendientes'
              TabOrder = 0
              object dbgrd_analipend: TdxDBGrid
                Left = 2
                Top = 15
                Width = 602
                Height = 204
                Bands = <
                  item
                  end>
                DefaultLayout = True
                HeaderPanelRowCount = 1
                KeyField = 'SLLAVE'
                ShowSummaryFooter = True
                SummaryGroups = <>
                SummarySeparator = ', '
                Align = alClient
                PopupMenu = PopupMenu1
                TabOrder = 0
                DataSource = dtsPendPag
                Filter.Criteria = {00000000}
                LookAndFeel = lfFlat
                OptionsBehavior = [edgoAutoSort, edgoDragScroll, edgoEnterShowEditor, edgoImmediateEditor, edgoTabThrough, edgoVertThrough]
                OptionsDB = [edgoCancelOnExit, edgoCanDelete, edgoCanInsert, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoSyncSelection, edgoUseBookmarks]
                OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
                OnColumnSorting = dbgrd_analipendColumnSorting
                OnCustomDraw = dbgrd_pronostmensCustomDraw
                object dbgrd_analipendMAYORIS: TdxDBGridMaskColumn
                  Visible = False
                  Width = 61
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'MAYORIS'
                end
                object dbgrd_analipendDOCTO: TdxDBGridMaskColumn
                  Alignment = taLeftJustify
                  Caption = 'Docto.'
                  Width = 38
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'DOCTO'
                end
                object dbgrd_analipendPAGARE: TdxDBGridMaskColumn
                  Alignment = taCenter
                  Caption = 'Pagare'
                  Width = 43
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'PAGARE'
                end
                object dbgrd_analipendCONSE: TdxDBGridMaskColumn
                  Visible = False
                  Width = 72
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'CONSE'
                end
                object dbgrd_analipendFECHA: TdxDBGridDateColumn
                  Caption = 'Fecha Fac.'
                  Width = 63
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'FECHA'
                end
                object dbgrd_analipendVENCE: TdxDBGridDateColumn
                  Caption = 'Vencimiento'
                  Width = 47
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'VENCE'
                end
                object dbgrd_analipendCONCEP: TdxDBGridMaskColumn
                  Caption = 'Concepto'
                  Width = 176
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'CONCEP'
                end
                object dbgrd_analipendCOA: TdxDBGridMaskColumn
                  Visible = False
                  Width = 32
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'COA'
                end
                object dbgrd_analipendIMPORTE: TdxDBGridCurrencyColumn
                  Caption = 'Imp.Original'
                  Width = 62
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'IMPORTE'
                  SummaryFooterType = cstSum
                  SummaryFooterField = 'IMPORTE'
                  SummaryFooterFormat = '#,##0.00'
                end
                object dbgrd_analipendSALDO: TdxDBGridCurrencyColumn
                  Caption = 'Saldo'
                  Width = 62
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'SALDO'
                  SummaryFooterType = cstSum
                  SummaryFooterField = 'SALDO'
                  SummaryFooterFormat = '#,##0.00'
                end
                object dbgrd_analipendACUM: TdxDBGridCurrencyColumn
                  Caption = 'Saldos Acumulados'
                  Width = 71
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'acum'
                end
                object dbgrd_analipendCIA: TdxDBGridMaskColumn
                  Visible = False
                  Width = 72
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'CIA'
                end
                object dbgrd_analipendTIPAGO: TdxDBGridMaskColumn
                  Visible = False
                  Width = 52
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'TIPAGO'
                end
                object dbgrd_analipendSLLAVE: TdxDBGridMaskColumn
                  Visible = False
                  Width = 171
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'SLLAVE'
                end
              end
            end
            object GroupBox13: TGroupBox
              Left = 0
              Top = 0
              Width = 177
              Height = 221
              Align = alLeft
              Caption = 'Facturas'
              TabOrder = 1
              object dbgrd_pendxmes: TdxDBGrid
                Left = 2
                Top = 15
                Width = 173
                Height = 204
                Bands = <
                  item
                  end>
                DefaultLayout = True
                HeaderPanelRowCount = 1
                KeyField = 'FECHAX'
                ShowSummaryFooter = True
                SummaryGroups = <>
                SummarySeparator = ', '
                Align = alClient
                PopupMenu = PopupMenu1
                TabOrder = 0
                DataSource = dtsSaldoMes
                Filter.Criteria = {00000000}
                LookAndFeel = lfUltraFlat
                OptionsBehavior = [edgoDragScroll, edgoEnterShowEditor, edgoImmediateEditor, edgoTabThrough, edgoVertThrough]
                OptionsDB = [edgoCancelOnExit, edgoCanDelete, edgoCanInsert, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoSyncSelection, edgoUseBookmarks]
                OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
                OnCustomDraw = dbgrd_pronostmensCustomDraw
                object dbgrd_pendxmesFECHAX: TdxDBGridMaskColumn
                  Caption = 'A�o/Mes'
                  Width = 56
                  BandIndex = 0
                  RowIndex = 0
                  HeaderMaxLineCount = 0
                  FieldName = 'FECHAX'
                  DisableFilter = True
                end
                object dbgrd_pendxmesSALDO: TdxDBGridCurrencyColumn
                  Caption = 'Saldo'
                  Width = 92
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'SALDO'
                  SummaryFooterType = cstSum
                  SummaryFooterField = 'SALDO'
                  SummaryFooterFormat = '$,0.00;-$,0.00'
                end
              end
            end
          end
          object Panel5: TPanel
            Left = 0
            Top = 224
            Width = 783
            Height = 211
            Align = alBottom
            BevelOuter = bvNone
            TabOrder = 1
            object Splitter6: TSplitter
              Left = 451
              Top = 0
              Width = 3
              Height = 211
              Cursor = crHSplit
              Align = alRight
            end
            object RzGroupBox4: TGroupBox
              Left = 454
              Top = 0
              Width = 329
              Height = 211
              Align = alRight
              Caption = 'Vencimientos '
              TabOrder = 1
              object dbgrd_vencxfac: TdxDBGrid
                Left = 2
                Top = 15
                Width = 325
                Height = 194
                Bands = <
                  item
                  end>
                DefaultLayout = True
                HeaderPanelRowCount = 1
                KeyField = 'PAGARE'
                ShowGroupPanel = True
                ShowSummaryFooter = True
                SummaryGroups = <
                  item
                    DefaultGroup = True
                    SummaryItems = <
                      item
                        SummaryField = 'CARGOS'
                        SummaryFormat = '#,##0.00'
                        SummaryType = cstSum
                      end
                      item
                        SummaryField = 'ABONOS'
                        SummaryFormat = '#,##0.00'
                        SummaryType = cstSum
                      end>
                    Name = 'dxDBGrid1SummaryGroup1'
                  end>
                SummarySeparator = ', '
                Align = alClient
                TabOrder = 0
                DataSource = dtsLetras
                Filter.Criteria = {00000000}
                GroupPanelColor = 8421440
                GroupPanelFontColor = clYellow
                LookAndFeel = lfUltraFlat
                OptionsBehavior = [edgoAutoSort, edgoDragScroll, edgoEnterShowEditor, edgoImmediateEditor, edgoTabThrough, edgoVertThrough]
                OptionsDB = [edgoCancelOnExit, edgoCanDelete, edgoCanInsert, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoSyncSelection, edgoUseBookmarks]
                OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
                ShowRowFooter = True
                OnCustomDraw = dbgrd_pronostmensCustomDraw
                object dxDBGridMaskColumn17: TdxDBGridMaskColumn
                  Visible = False
                  Width = 70
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'MAYORIS'
                end
                object dxDBGridMaskColumn18: TdxDBGridMaskColumn
                  Visible = False
                  Width = 38
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'DOCTO'
                end
                object dxDBGridMaskColumn19: TdxDBGridMaskColumn
                  Alignment = taCenter
                  Caption = 'Lta'
                  Width = 38
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'PAGARE'
                end
                object dxDBGridDateColumn3: TdxDBGridDateColumn
                  Alignment = taCenter
                  Caption = 'Vencim.'
                  Width = 73
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'VENCE'
                end
                object dxDBGridCurrencyColumn8: TdxDBGridCurrencyColumn
                  Caption = 'Imp. Letra'
                  Width = 94
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'IMPORTE'
                end
                object dxDBGridImageColumn1: TdxDBGridImageColumn
                  Alignment = taLeftJustify
                  Caption = 'Pagado'
                  MinWidth = 16
                  Width = 50
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'SGRAFICO'
                  Descriptions.Strings = (
                    'Pago Atrasado'
                    'Pago Puntual'
                    'Atrasado')
                  Images = ImageList1
                  ImageIndexes.Strings = (
                    '0'
                    '1'
                    '2')
                  LargeImages = ImageList1
                  Values.Strings = (
                    'PATRASADO'
                    'PUNTUAL'
                    'VENCIDO')
                end
                object dxDBGridMaskColumn20: TdxDBGridMaskColumn
                  Alignment = taCenter
                  Caption = 'Fecha Pago'
                  Width = 86
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'SFECHAPAGO'
                end
              end
            end
            object GroupBox7: TGroupBox
              Left = 0
              Top = 0
              Width = 451
              Height = 211
              Align = alClient
              Caption = 'Abonos'
              TabOrder = 0
              object dbgrd_formpagofac: TdxDBGrid
                Left = 2
                Top = 15
                Width = 447
                Height = 194
                Bands = <
                  item
                  end>
                DefaultLayout = True
                HeaderPanelRowCount = 1
                KeyField = 'CONSE'
                ShowSummaryFooter = True
                SummaryGroups = <>
                SummarySeparator = ', '
                Align = alClient
                PopupMenu = PopupMenu1
                TabOrder = 0
                DataSource = dtsForPago
                Filter.Criteria = {00000000}
                LookAndFeel = lfUltraFlat
                OptionsBehavior = [edgoAutoSort, edgoDragScroll, edgoEnterShowEditor, edgoImmediateEditor, edgoTabThrough, edgoVertThrough]
                OptionsDB = [edgoCancelOnExit, edgoCanDelete, edgoCanInsert, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoSyncSelection, edgoUseBookmarks]
                OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
                OnCustomDraw = dbgrd_pronostmensCustomDraw
                object dxDBGridMaskColumn21: TdxDBGridMaskColumn
                  Visible = False
                  Width = 59
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'MAYORIS'
                end
                object dxDBGridMaskColumn22: TdxDBGridMaskColumn
                  Caption = 'Docto'
                  Width = 57
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'DOCTO'
                end
                object dxDBGridMaskColumn23: TdxDBGridMaskColumn
                  Alignment = taCenter
                  Caption = 'Pagare'
                  Width = 50
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'PAGARE'
                end
                object dxDBGridMaskColumn24: TdxDBGridMaskColumn
                  Visible = False
                  Width = 46
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'CONSE'
                end
                object dxDBGridDateColumn4: TdxDBGridDateColumn
                  Caption = 'Fecha'
                  Width = 70
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'FECHA'
                end
                object dxDBGridDateColumn5: TdxDBGridDateColumn
                  Visible = False
                  Width = 45
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'VENCE'
                end
                object dxDBGridMaskColumn25: TdxDBGridMaskColumn
                  Caption = 'Concepto'
                  Width = 200
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'CONCEP'
                end
                object dxDBGridMaskColumn26: TdxDBGridMaskColumn
                  Visible = False
                  Width = 30
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'COA'
                end
                object dxDBGridCurrencyColumn9: TdxDBGridCurrencyColumn
                  Caption = 'Importe Pago'
                  Width = 75
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'IMPORTE'
                  SummaryFooterType = cstSum
                  SummaryFooterField = 'IMPORTE'
                  SummaryFooterFormat = '#,##0.00'
                end
                object dxDBGridCurrencyColumn10: TdxDBGridCurrencyColumn
                  Visible = False
                  Width = 45
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'SALDO'
                end
                object dxDBGridMaskColumn27: TdxDBGridMaskColumn
                  Visible = False
                  Width = 25
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'CIA'
                end
                object dxDBGridMaskColumn28: TdxDBGridMaskColumn
                  Visible = False
                  Width = 49
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'TIPAGO'
                end
                object dxDBGridColumn1: TdxDBGridColumn
                  Caption = 'Tipo de Pago'
                  Width = 120
                  BandIndex = 0
                  RowIndex = 0
                  FieldName = 'STIPOPAGO'
                end
              end
            end
          end
        end
        object tbs_graffacxabono: TTabSheet
          Caption = 'Grafica de Compras Anuales'
          ImageIndex = 3
          OnShow = tbs_graffacxabonoShow
          object char_comprasanual: TChart
            Left = 0
            Top = 0
            Width = 783
            Height = 435
            AllowPanning = pmNone
            BackWall.Brush.Color = clWhite
            BackWall.Brush.Style = bsClear
            Title.Text.Strings = (
              'TChart')
            Legend.Alignment = laBottom
            View3D = False
            Align = alClient
            PopupMenu = PopupMenuGraf
            TabOrder = 0
            object chartserie_anuantier: TLineSeries
              Marks.Arrow.Color = clBlue
              Marks.ArrowLength = 8
              Marks.Visible = False
              SeriesColor = clRed
              VertAxis = aBothVertAxis
              Pointer.InflateMargins = True
              Pointer.Style = psTriangle
              Pointer.Visible = True
              XValues.DateTime = False
              XValues.Name = 'X'
              XValues.Multiplier = 1
              XValues.Order = loAscending
              YValues.DateTime = False
              YValues.Name = 'Y'
              YValues.Multiplier = 1
              YValues.Order = loNone
            end
            object chartserie_anuayer: TLineSeries
              Marks.Arrow.Color = clRed
              Marks.ArrowLength = 8
              Marks.Visible = False
              SeriesColor = clBlue
              VertAxis = aBothVertAxis
              Pointer.InflateMargins = True
              Pointer.Style = psCircle
              Pointer.Visible = True
              XValues.DateTime = False
              XValues.Name = 'X'
              XValues.Multiplier = 1
              XValues.Order = loAscending
              YValues.DateTime = False
              YValues.Name = 'Y'
              YValues.Multiplier = 1
              YValues.Order = loNone
            end
            object chartserie_anuhoy: TLineSeries
              Marks.Arrow.Color = clGreen
              Marks.ArrowLength = 8
              Marks.Visible = False
              SeriesColor = clGreen
              VertAxis = aBothVertAxis
              Pointer.InflateMargins = True
              Pointer.Style = psRectangle
              Pointer.Visible = True
              XValues.DateTime = False
              XValues.Name = 'X'
              XValues.Multiplier = 1
              XValues.Order = loAscending
              YValues.DateTime = False
              YValues.Name = 'Y'
              YValues.Multiplier = 1
              YValues.Order = loNone
            end
          end
        end
        object tbs_charcomprapago: TTabSheet
          Caption = 'Compras - Pagos'
          ImageIndex = 4
          OnShow = tbs_graffacxabonoShow
          object char_compraspagos: TChart
            Left = 0
            Top = 0
            Width = 783
            Height = 435
            AllowPanning = pmNone
            BackWall.Brush.Color = clWhite
            BackWall.Brush.Style = bsClear
            Title.Text.Strings = (
              'TChart')
            Legend.Alignment = laBottom
            Legend.TopPos = 9
            Align = alClient
            BevelOuter = bvNone
            PopupMenu = PopupMenuGraf
            TabOrder = 0
            object chartserie_compras: TBarSeries
              Marks.ArrowLength = 8
              Marks.Visible = False
              SeriesColor = clRed
              Title = 'chartserie_compras'
              VertAxis = aBothVertAxis
              SideMargins = False
              XValues.DateTime = False
              XValues.Name = 'X'
              XValues.Multiplier = 1
              XValues.Order = loAscending
              YValues.DateTime = False
              YValues.Name = 'Bar'
              YValues.Multiplier = 1
              YValues.Order = loNone
            end
            object chartserie_pagos: TBarSeries
              Marks.ArrowLength = 8
              Marks.Visible = False
              SeriesColor = clGreen
              Title = 'chartserie_pagos'
              VertAxis = aBothVertAxis
              SideMargins = False
              XValues.DateTime = False
              XValues.Name = 'X'
              XValues.Multiplier = 1
              XValues.Order = loAscending
              YValues.DateTime = False
              YValues.Name = 'Bar'
              YValues.Multiplier = 1
              YValues.Order = loNone
            end
          end
        end
        object tbs_cobranza: TTabSheet
          Caption = 'Grafica de Cobranza'
          ImageIndex = 5
          OnShow = tbs_graffacxabonoShow
          object char_cobranza: TChart
            Left = 0
            Top = 0
            Width = 745
            Height = 439
            AllowPanning = pmNone
            BackWall.Brush.Color = clWhite
            BackWall.Brush.Style = bsClear
            Title.Text.Strings = (
              'TChart')
            Legend.Alignment = laBottom
            View3D = False
            Align = alClient
            PopupMenu = PopupMenuGraf
            TabOrder = 0
            object chartserie_cobranza: TLineSeries
              Marks.Arrow.Color = clBlue
              Marks.ArrowLength = 8
              Marks.Visible = False
              SeriesColor = clRed
              VertAxis = aBothVertAxis
              Pointer.InflateMargins = True
              Pointer.Style = psRectangle
              Pointer.Visible = True
              XValues.DateTime = False
              XValues.Name = 'X'
              XValues.Multiplier = 1
              XValues.Order = loAscending
              YValues.DateTime = False
              YValues.Name = 'Y'
              YValues.Multiplier = 1
              YValues.Order = loNone
            end
            object chartserie_pagos2: TLineSeries
              Marks.Arrow.Color = clRed
              Marks.ArrowLength = 8
              Marks.Visible = False
              SeriesColor = clBlue
              VertAxis = aBothVertAxis
              Pointer.InflateMargins = True
              Pointer.Style = psRectangle
              Pointer.Visible = False
              XValues.DateTime = False
              XValues.Name = 'X'
              XValues.Multiplier = 1
              XValues.Order = loAscending
              YValues.DateTime = False
              YValues.Name = 'Y'
              YValues.Multiplier = 1
              YValues.Order = loNone
            end
          end
        end
        object tbs_cartera: TTabSheet
          Caption = 'Grafica de Cartera'
          ImageIndex = 6
          OnShow = tbs_graffacxabonoShow
          object char_cartera: TChart
            Left = 0
            Top = 0
            Width = 783
            Height = 435
            AllowPanning = pmNone
            BackWall.Brush.Color = clWhite
            BackWall.Brush.Style = bsClear
            Title.Text.Strings = (
              'TChart')
            Legend.Alignment = laBottom
            View3D = False
            Align = alClient
            PopupMenu = PopupMenuGraf
            TabOrder = 0
            object chartserie_deuda: TLineSeries
              Marks.Arrow.Color = clBlue
              Marks.ArrowLength = 8
              Marks.Style = smsLabelPercent
              Marks.Visible = False
              SeriesColor = clRed
              VertAxis = aBothVertAxis
              Dark3D = False
              Pointer.InflateMargins = True
              Pointer.Style = psRectangle
              Pointer.Visible = True
              XValues.DateTime = False
              XValues.Name = 'X'
              XValues.Multiplier = 1
              XValues.Order = loAscending
              YValues.DateTime = False
              YValues.Name = 'Y'
              YValues.Multiplier = 1
              YValues.Order = loNone
            end
            object chartserie_cartera: TLineSeries
              Marks.Arrow.Color = clRed
              Marks.ArrowLength = 8
              Marks.Visible = False
              SeriesColor = clBlue
              VertAxis = aBothVertAxis
              Pointer.InflateMargins = True
              Pointer.Style = psTriangle
              Pointer.Visible = True
              XValues.DateTime = False
              XValues.Name = 'X'
              XValues.Multiplier = 1
              XValues.Order = loAscending
              YValues.DateTime = False
              YValues.Name = 'Y'
              YValues.Multiplier = 1
              YValues.Order = loNone
            end
          end
        end
        object TabSheet3: TTabSheet
          Caption = 'Capturas'
          ImageIndex = 7
          object GroupBox4: TGroupBox
            Left = 517
            Top = 0
            Width = 266
            Height = 435
            Align = alRight
            Caption = 'Teclee los Datos del Mayorista'
            TabOrder = 0
            object Label16: TLabel
              Left = 92
              Top = 32
              Width = 30
              Height = 13
              Caption = 'Fecha'
            end
            object Label17: TLabel
              Left = 88
              Top = 52
              Width = 34
              Height = 13
              Caption = 'Cartera'
            end
            object Label18: TLabel
              Left = 14
              Top = 75
              Width = 108
              Height = 13
              Caption = 'Documentos Cobrados'
            end
            object Label19: TLabel
              Left = 8
              Top = 136
              Width = 179
              Height = 13
              Caption = 'Seleccione la Fecha y presione Enter,'
            end
            object Label20: TLabel
              Left = 8
              Top = 152
              Width = 131
              Height = 13
              Caption = 'posteriormente proporcione '
            end
            object Label28: TLabel
              Left = 8
              Top = 168
              Width = 205
              Height = 13
              Caption = 'los datos y haga click sobre el bot�n de OK'
            end
            object date_fecedomay: TDateTimePicker
              Left = 125
              Top = 27
              Width = 120
              Height = 21
              CalAlignment = dtaLeft
              Date = 38863.508123912
              Time = 38863.508123912
              DateFormat = dfShort
              DateMode = dmComboBox
              Kind = dtkDate
              ParseInput = False
              TabOrder = 0
              OnKeyDown = date_fecedomayKeyDown
            end
            object edt_cartera: TdxCurrencyEdit
              Left = 125
              Top = 49
              Width = 120
              TabOrder = 1
            end
            object edt_cobranza: TdxCurrencyEdit
              Left = 125
              Top = 72
              Width = 120
              TabOrder = 2
            end
            object btn_grabadatomay: TBitBtn
              Left = 128
              Top = 104
              Width = 75
              Height = 25
              Caption = 'OK'
              ModalResult = 1
              TabOrder = 3
              OnClick = btn_grabadatomayClick
              Glyph.Data = {
                DE010000424DDE01000000000000760000002800000024000000120000000100
                0400000000006801000000000000000000001000000000000000000000000000
                80000080000000808000800000008000800080800000C0C0C000808080000000
                FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
                3333333333333333333333330000333333333333333333333333F33333333333
                00003333344333333333333333388F3333333333000033334224333333333333
                338338F3333333330000333422224333333333333833338F3333333300003342
                222224333333333383333338F3333333000034222A22224333333338F338F333
                8F33333300003222A3A2224333333338F3838F338F33333300003A2A333A2224
                33333338F83338F338F33333000033A33333A222433333338333338F338F3333
                0000333333333A222433333333333338F338F33300003333333333A222433333
                333333338F338F33000033333333333A222433333333333338F338F300003333
                33333333A222433333333333338F338F00003333333333333A22433333333333
                3338F38F000033333333333333A223333333333333338F830000333333333333
                333A333333333333333338330000333333333333333333333333333333333333
                0000}
              NumGlyphs = 2
            end
          end
          object Panel6: TPanel
            Left = 0
            Top = 0
            Width = 517
            Height = 435
            Align = alClient
            BevelOuter = bvNone
            TabOrder = 1
            object GroupBox10: TGroupBox
              Left = 0
              Top = 0
              Width = 517
              Height = 201
              Align = alTop
              Caption = 'Datos Generales'
              TabOrder = 0
              object Label15: TLabel
                Left = 30
                Top = 23
                Width = 33
                Height = 13
                Caption = '&C�digo'
                FocusControl = edt_codvnd
              end
              object Label21: TLabel
                Left = 26
                Top = 45
                Width = 37
                Height = 13
                Caption = '&Nombre'
                FocusControl = edt_nombre
              end
              object Label22: TLabel
                Left = 20
                Top = 69
                Width = 43
                Height = 13
                Caption = 'Nombre2'
              end
              object Label23: TLabel
                Left = 18
                Top = 92
                Width = 45
                Height = 13
                Caption = '&Direcci�n'
                FocusControl = edt_direc
              end
              object Label24: TLabel
                Left = 16
                Top = 116
                Width = 47
                Height = 13
                Caption = 'P&oblaci�n'
              end
              object Label25: TLabel
                Left = 33
                Top = 136
                Width = 30
                Height = 13
                Caption = '&R.F.C.'
                FocusControl = edt_rfc
              end
              object Label26: TLabel
                Left = 245
                Top = 138
                Width = 63
                Height = 13
                Caption = '% Descuento'
                FocusControl = edt_pdsc
              end
              object Label27: TLabel
                Left = 21
                Top = 160
                Width = 42
                Height = 13
                Caption = '&Tel�fono'
                FocusControl = edt_tel
              end
              object edt_codvnd: TEdit
                Left = 66
                Top = 19
                Width = 47
                Height = 21
                CharCase = ecUpperCase
                MaxLength = 4
                TabOrder = 0
              end
              object edt_nombre: TdxEdit
                Left = 66
                Top = 42
                Width = 401
                TabOrder = 1
                CharCase = ecUpperCase
              end
              object edt_nombre2: TEdit
                Left = 66
                Top = 65
                Width = 401
                Height = 21
                CharCase = ecUpperCase
                TabOrder = 2
              end
              object edt_direc: TdxEdit
                Left = 66
                Top = 89
                Width = 401
                TabOrder = 3
                CharCase = ecUpperCase
              end
              object edt_ciu: TEdit
                Left = 66
                Top = 112
                Width = 401
                Height = 21
                CharCase = ecUpperCase
                TabOrder = 4
              end
              object edt_rfc: TdxEdit
                Left = 66
                Top = 135
                Width = 161
                TabOrder = 5
                CharCase = ecUpperCase
                MaxLength = 15
                StoredValues = 2
              end
              object edt_pdsc: TdxCurrencyEdit
                Left = 314
                Top = 135
                Width = 50
                TabOrder = 6
                Alignment = taRightJustify
                DecimalPlaces = 3
                DisplayFormat = '0.000'
                StoredValues = 1
              end
              object edt_tel: TdxEdit
                Left = 66
                Top = 158
                Width = 161
                TabOrder = 7
                CharCase = ecUpperCase
              end
            end
            object dbgrd_telefonos: TdxDBGrid
              Left = 0
              Top = 201
              Width = 517
              Height = 234
              Bands = <
                item
                end>
              DefaultLayout = True
              HeaderPanelRowCount = 1
              KeyField = 'IDRELAC'
              SummaryGroups = <>
              SummarySeparator = ', '
              Align = alClient
              PopupMenu = PopupMenu1
              TabOrder = 1
              DataSource = dts_mayrelac
              Filter.Criteria = {00000000}
              OptionsDB = [edgoCancelOnExit, edgoCanInsert, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoUseBookmarks, edgoUseLocate]
              OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
              object dbgrd_telefonosTIPOTEL: TdxDBGridMaskColumn
                Caption = 'Telefono De'
                BandIndex = 0
                RowIndex = 0
                FieldName = 'TIPOTEL'
              end
              object dbgrd_telefonosNUMTEL: TdxDBGridMaskColumn
                Caption = 'Numero'
                BandIndex = 0
                RowIndex = 0
                FieldName = 'TELFAX'
              end
            end
          end
        end
        object tbs_observaciones: TTabSheet
          Caption = 'Observaciones'
          ImageIndex = 8
          object pnl_cmdobs: TPanel
            Left = 0
            Top = 0
            Width = 783
            Height = 41
            Align = alTop
            BevelOuter = bvNone
            TabOrder = 0
            object BitBtn2: TBitBtn
              Left = 128
              Top = 8
              Width = 209
              Height = 25
              Action = observs_may
              Caption = 'Observaciones Mayoreo'
              TabOrder = 0
              Glyph.Data = {
                36040000424D3604000000000000360000002800000010000000100000000100
                2000000000000004000000000000000000000000000000000000FF00FF00FF00
                FF00FF00FF00FF00FF0000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000FF00FF00FF00
                FF00FF00FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
                FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FF00FF00FF00
                FF00FF00FF00FF00FF0000000000FFFFFF00000000000000000000000000FFFF
                FF0000000000FFFFFF000000000000000000FFFFFF0000000000FF00FF00FF00
                FF00FF00FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
                FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FF00FF00FF00
                FF00FF00FF00FF00FF0000000000FFFFFF000000000000000000FFFFFF000000
                000000000000FFFFFF000000000000000000FFFFFF0000000000FF00FF00FF00
                FF00FF00FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
                FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FF00FF00FF00
                FF00FF00FF00FF00FF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
                FF000000000000000000FFFFFF0000000000FFFFFF0000000000FF00FF00FF00
                FF00FF00FF0000000000FFFFFF0000FFFF000000000000000000FFFFFF000000
                0000FFFFFF0000000000FFFFFF00FFFFFF00FFFFFF0000000000FF00FF00FF00
                FF0000000000FFFFFF0000FFFF000000000000FFFF00FFFFFF0000000000FFFF
                FF0000FFFF0000000000FFFFFF0000000000FFFFFF0000000000FF00FF000000
                0000FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000000000FFFFFF0000FF
                FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FF00FF000000
                000000FFFF00FFFFFF0000FFFF00FFFFFF0000000000FFFFFF0000FFFF000000
                0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000000000000000
                0000FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF0000000000FFFF
                FF00FFFFFF00FFFFFF0000000000000000000000000000000000FFFF00000000
                000000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF0000000000000000000000
                0000FFFFFF00FFFFFF0000000000FFFFFF00FFFFFF0000000000FFFF0000FFFF
                00000000000000FFFF00FFFFFF0000FFFF000000000000FFFF00FFFFFF0000FF
                FF0000000000FFFFFF0000000000FFFFFF0000000000FF00FF00FFFF0000FFFF
                0000FFFF00000000000000FFFF00FFFFFF0000FFFF00FFFFFF00000000000000
                0000FFFFFF00FFFFFF000000000000000000FF00FF00FF00FF00FFFF0000FFFF
                0000FFFF0000FFFF000000000000000000000000000000000000000000000000
                0000000000000000000000000000FF00FF00FF00FF00FF00FF00}
            end
          end
          object dbgrd_observs: TdxDBGrid
            Left = 0
            Top = 41
            Width = 783
            Height = 394
            Bands = <
              item
              end>
            DefaultLayout = True
            HeaderPanelRowCount = 1
            KeyField = 'FECHA'
            SummaryGroups = <>
            SummarySeparator = ', '
            Align = alClient
            PopupMenu = PopupMenu1
            TabOrder = 1
            DataSource = dts_observs
            Filter.Active = True
            Filter.AutoDataSetFilter = True
            Filter.Criteria = {00000000}
            OptionsDB = [edgoCancelOnExit, edgoCanDelete, edgoCanInsert, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoUseBookmarks]
            OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
            object dbgrd_observsFECHA: TdxDBGridDateColumn
              Caption = 'Fecha'
              BandIndex = 0
              RowIndex = 0
              FieldName = 'FECHA'
            end
            object dbgrd_observsOBSERVS: TdxDBGridMaskColumn
              Caption = 'Observaciones'
              BandIndex = 0
              RowIndex = 0
              FieldName = 'OBSERVS'
            end
          end
        end
      end
      object Panel7: TPanel
        Left = 0
        Top = 0
        Width = 791
        Height = 126
        Align = alTop
        TabOrder = 1
        object Label3: TLabel
          Left = 16
          Top = 8
          Width = 36
          Height = 13
          Caption = 'Mayoris'
        end
        object Label4: TLabel
          Left = 24
          Top = 32
          Width = 91
          Height = 13
          Caption = 'Vencido mas de 30'
        end
        object Label10: TLabel
          Left = 293
          Top = 31
          Width = 36
          Height = 13
          Caption = 'Exigible'
        end
        object Label11: TLabel
          Left = 236
          Top = 101
          Width = 93
          Height = 13
          Caption = 'Ingresos Esperados'
        end
        object Label9: TLabel
          Left = 265
          Top = 82
          Width = 64
          Height = 13
          Caption = '67% x vencer'
        end
        object Label8: TLabel
          Left = 267
          Top = 58
          Width = 62
          Height = 13
          Caption = '10% Vencido'
        end
        object Label13: TLabel
          Left = 479
          Top = 56
          Width = 54
          Height = 13
          Caption = '% Cumplido'
        end
        object Label12: TLabel
          Left = 497
          Top = 33
          Width = 36
          Height = 13
          Caption = 'Abonos'
        end
        object Label29: TLabel
          Left = 511
          Top = 104
          Width = 21
          Height = 13
          Caption = 'Tipo'
        end
        object Label7: TLabel
          Left = 23
          Top = 103
          Width = 92
          Height = 13
          Caption = 'X Vencer a 30 Dias'
        end
        object Label5: TLabel
          Left = 2
          Top = 56
          Width = 113
          Height = 13
          Caption = 'Vencido de 1 a 30 D�as'
        end
        object Label6: TLabel
          Left = 49
          Top = 80
          Width = 66
          Height = 13
          Caption = 'Vencido Total'
        end
        object Label30: TLabel
          Left = 470
          Top = 9
          Width = 19
          Height = 13
          Caption = 'A�o'
        end
        object Label31: TLabel
          Left = 563
          Top = 8
          Width = 20
          Height = 13
          Caption = 'Mes'
        end
        object lkcmb_mayoris: TDBLookupComboBox
          Left = 64
          Top = 3
          Width = 55
          Height = 21
          DropDownWidth = 200
          KeyField = 'CODIGO'
          ListField = 'CODIGO; NOMBRE'
          ListSource = dts_edoanu
          TabOrder = 0
          OnExit = lkcmb_mayorisExit
          OnKeyDown = lkcmb_mayorisKeyDown
        end
        object DBEdit1: TDBEdit
          Left = 120
          Top = 3
          Width = 315
          Height = 21
          DataField = 'NOMBRE'
          DataSource = dts_edoanu
          TabOrder = 1
        end
        object dxDBCurrencyEdit2: TdxDBCurrencyEdit
          Left = 119
          Top = 27
          Width = 100
          TabOrder = 2
          DataField = 'ANTVENC'
          DataSource = dts_pronost
        end
        object dxDBCurrencyEdit8: TdxDBCurrencyEdit
          Left = 335
          Top = 27
          Width = 100
          TabOrder = 3
          DataField = 'EXIGIBLE'
          DataSource = dts_pronost
        end
        object dxDBCurrencyEdit6: TdxDBCurrencyEdit
          Left = 335
          Top = 51
          Width = 100
          TabOrder = 4
          DataField = 'PAGOANTVEN'
          DataSource = dts_pronost
        end
        object dxDBCurrencyEdit7: TdxDBCurrencyEdit
          Left = 335
          Top = 75
          Width = 100
          TabOrder = 5
          DataField = 'PAGONVOVEN'
          DataSource = dts_pronost
        end
        object dxDBCurrencyEdit9: TdxDBCurrencyEdit
          Left = 335
          Top = 99
          Width = 100
          TabOrder = 6
          DataField = 'ABONOESP'
          DataSource = dts_pronost
        end
        object dxDBCurrencyEdit10: TdxDBCurrencyEdit
          Left = 535
          Top = 27
          Width = 100
          TabOrder = 7
          DataField = 'ABONOS'
          DataSource = dts_pronost
        end
        object dxDBCurrencyEdit11: TdxDBCurrencyEdit
          Left = 535
          Top = 51
          Width = 100
          TabOrder = 8
          DataField = 'PORCEN'
          DataSource = dts_pronost
          DisplayFormat = ',0.00%;-,0.00%'
          StoredValues = 0
        end
        object dxDBCurrencyEdit1: TdxDBCurrencyEdit
          Left = 536
          Top = 75
          Width = 100
          TabOrder = 9
          DataField = 'SALDO'
          DataSource = dts_edoanu
        end
        object dbedt_descri: TDBEdit
          Left = 536
          Top = 99
          Width = 100
          Height = 21
          DataField = 'descri'
          DataSource = dts_edoanu
          TabOrder = 10
        end
        object dxDBCurrencyEdit4: TdxDBCurrencyEdit
          Left = 119
          Top = 75
          Width = 100
          TabOrder = 11
          DataField = 'VENCTOT'
          DataSource = dts_pronost
        end
        object dxDBCurrencyEdit3: TdxDBCurrencyEdit
          Left = 119
          Top = 51
          Width = 100
          TabOrder = 12
          DataField = 'NVOVENC'
          DataSource = dts_pronost
        end
        object dxDBCurrencyEdit5: TdxDBCurrencyEdit
          Left = 119
          Top = 99
          Width = 100
          TabOrder = 13
          DataField = 'PORVENC'
          DataSource = dts_pronost
        end
        object edt_anumay: TdxSpinEdit
          Left = 493
          Top = 4
          Width = 61
          TabOrder = 14
          OnKeyDown = edt_anumayKeyDown
        end
        object edt_mesmay: TdxSpinEdit
          Left = 586
          Top = 4
          Width = 61
          TabOrder = 15
          OnKeyDown = edt_anumayKeyDown
          OnChange = edt_mesmayChange
        end
        object BitBtn1: TBitBtn
          Left = 656
          Top = 2
          Width = 75
          Height = 25
          Action = WindowClose1
          Caption = '&Salir'
          TabOrder = 16
          Glyph.Data = {
            36040000424D3604000000000000360000002800000010000000100000000100
            2000000000000004000000000000000000000000000000000000FF00FF00FF00
            FF00000000000000000000000000000000000000000000000000000000000000
            0000000000000000000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00000000000000840000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FF
            FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF0000000000000084000000840000FFFF0000FFFF0000FFFF0000FFFF0000FF
            FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF000000000000008400000084000000840000FFFF0000FFFF0000FFFF0000FF
            FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00000000000000840000008400000084000000000000FFFF0000FFFF0000FF
            FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00000000000000840000008400000084000000000000FFFF0000FFFF0000FF
            FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00000000000000840000008400000084000000000000FFFF0000FFFF0000FF
            FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00000000000000840000008400000084000000000000FFFF0000FFFF0000FF
            FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00000000000000840000008400000084000000000000FFFF0000FFFF0000FF
            FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00000000000000840000008400000084000000000000FFFF0000FFFF0000FF
            FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF000000000000008400000084000000840000FFFF000000000000FFFF0000FF
            FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00000000000000840000008400000084000000000000FFFF0000FFFF0000FF
            FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00000000000000840000008400000084000000000000FFFF0000FFFF0000FF
            FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF000000000000008400FFFF0000000084000000000000FFFF0000FFFF0000FF
            FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF000000000000008400FFFF0000FFFF00000000000000FFFF0000FFFF0000FF
            FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00000000000000000000000000000000000000000000000000000000000000
            0000000000000000000000000000FF00FF00FF00FF00FF00FF00}
        end
      end
    end
  end
  object dtsMovCli2: TDataSource
    Left = 112
    Top = 135
  end
  object qsMovCli2: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select mayoris,docto,pagare,conse,fecha,vence,concep,coa,importe' +
        ',saldo,cia,tipago,'
      
        'cast( (case coa when '#39'C'#39' then importe else 0 end) as Double Prec' +
        'ision) as Cargos,'
      
        'cast( (case coa when '#39'A'#39' then importe else 0 end) as Double Prec' +
        'ision) as Abonos, '
      
        'cast((mayoris || cast(docto as varchar(12) ) || cast(pagare as v' +
        'archar(6) ) ) as varchar(25) ) as sLlave,'
      '(case coa when '#39'A'#39' then '
      '          (case tipago when '#39'E'#39' then '#39'EFECTIVO'#39
      #9#9'               when '#39'B'#39' then '#39'BONIFICACION'#39
      #9#9#9#9#9'   when '#39'D'#39' then '#39'DEVOLUCION'#39
      #9#9'  end)'
      #9#9'  when '#39'C'#39' then '#39'PAGARE'#39
      'end) as sTipoPago,'
      'tipofac'
      
        'from movmay2 where mayoris = :Mayoris and fecha >= :FechaIni and' +
        ' fecha <= :FechaFin and cia = :Cia'
      'order by fecha')
    Left = 84
    Top = 135
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'Mayoris'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'FechaIni'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'FechaFin'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'Cia'
        ParamType = ptUnknown
      end>
  end
  object qsPendPag: TQuery
    CachedUpdates = True
    AfterScroll = qsPendPagAfterScroll
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select mayoris,docto,pagare,conse,fecha,vence,concep,coa,importe' +
        ',saldo,cia,tipago,'
      'tipofac,0 as acum,'
      
        'cast( extract(YEAR  from vence) * 100 + extract(month from vence' +
        ') as varchar(6) ) as venc,'
      
        'cast((mayoris || cast(docto as varchar(12) ) || cast(pagare as v' +
        'archar(6) ) ) as varchar(25) ) as sLlave'
      'from movmay2 where'
      
        'mayoris = :Mayoris and saldo > 0.05 and vence between :VENCINI a' +
        'nd :VENCFIN'
      'and coa = '#39'C'#39' and cia = :Cia'
      'order by fecha'
      ' ')
    UpdateObject = uqry_qsPendPag
    Left = 128
    Top = 301
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'Mayoris'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'VENCINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'VENCFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'Cia'
        ParamType = ptUnknown
      end>
  end
  object dtsPendPag: TDataSource
    DataSet = qsPendPag
    Left = 168
    Top = 315
  end
  object qsForPago: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select mayoris,docto,pagare,conse,fecha,vence,concep,coa,importe' +
        ',saldo,cia,tipago,'
      'tipofac,'
      ' (case tipago when '#39'E'#39' then '#39'EFECTIVO'#39
      '               when '#39'B'#39' then '#39'BONIFICACION'#39
      '              when '#39'D'#39' then '#39'DEVOLUCION'#39
      '  end) as sTipoPago'
      'from movmay2'
      'where mayoris = :Mayoris and coa = '#39'A'#39' and docto = :Docto'
      'and tipofac = :TIPOFAC and cia = :Cia'
      'order by fecha')
    Left = 348
    Top = 330
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'Mayoris'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'Docto'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'TIPOFAC'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'Cia'
        ParamType = ptUnknown
      end>
  end
  object dtsForPago: TDataSource
    DataSet = qsForPago
    Left = 348
    Top = 360
  end
  object qsSumSaldo: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select sum(saldo) as SaldoTot from movmay2 where mayoris = :Mayo' +
        'ris and saldo > .05 and coa = '#39'C'#39' and cia = :Cia')
    Left = 68
    Top = 300
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'Mayoris'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'Cia'
        ParamType = ptUnknown
      end>
  end
  object qry_facturas: TQuery
    CachedUpdates = True
    AfterScroll = qry_facturasAfterScroll
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select a.cia, a.mayoris, a.num, a.fecha, a.Total as total,'
      'a.npagos, a.plazo, a.tipofac,'
      'c.descri, 0 as acum,'
      
        'cast((case a.tipago when '#39'M'#39' then '#39'MERCANCIA'#39' when '#39'I'#39' then '#39'INT' +
        'ERESES'#39' when '#39'O'#39' then '#39'MORATORIOS'#39' end) as varchar(15) ) as sTip' +
        'ago,'
      
        'cast(extract(YEAR  from a.fecha) * 100 + extract(month from a.fe' +
        'cha) as varchar(6) ) as fech,'
      'b.vence as primerven'
      'from facturma a'
      'join tipo_facturma c on a.tipofac = c.tipofac'
      'left outer join movmay2 b on'
      
        'a.mayoris = b.mayoris and a.num = b.docto and a.cia = b.cia and ' +
        'b.pagare = 1 and b.coa = '#39'C'#39
      'and a.tipofac = b.tipofac'
      
        'where a.mayoris = :Mayoris and a.fecha between :FechaIni and :Fe' +
        'chaFin and a.cia = :Cia'
      'and mayomen = '#39'Y'#39
      'order by a.fecha, a.num'
      ' ')
    UpdateObject = uqry_facturas
    Left = 32
    Top = 318
    ParamData = <
      item
        DataType = ftString
        Name = 'Mayoris'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FechaIni'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FechaFin'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'Cia'
        ParamType = ptUnknown
      end>
  end
  object dts_facturas: TDataSource
    DataSet = qry_facturas
    Left = 32
    Top = 346
  end
  object qsLetras: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select a.mayoris, a.importe, a.docto, a.Vence, a.pagare,'
      
        'cast((select max(fecha) from movmay2 where mayoris = a.Mayoris a' +
        'nd docto = a.docto and tipofac = a.tipofac and coa = '#39'A'#39' and pag' +
        'are = a.pagare) as Date ) as sFechaPago,'
      
        '(select sum(importe) from movmay2 where mayoris = a.Mayoris and ' +
        'docto = a.docto and coa = '#39'A'#39' and pagare = a.pagare and tipofac ' +
        '= a.tipofac) as imppago,'
      'cast('#39#39' as varchar(20) ) as sGrafico'
      'from movmay2 a'
      'where a.mayoris = :Mayoris and a.docto = :Documento'
      'and a.tipofac = :TIPOFAC and a.coa = '#39'C'#39' and cia = :Cia'
      'order by a.docto, a.pagare'
      '')
    UpdateObject = uqsLetras
    Left = 598
    Top = 86
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'Mayoris'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'Documento'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'TIPOFAC'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'Cia'
        ParamType = ptUnknown
      end>
  end
  object dtsLetras: TDataSource
    AutoEdit = False
    DataSet = qsLetras
    Left = 598
    Top = 126
  end
  object ImageList1: TImageList
    Left = 352
    Top = 208
    Bitmap = {
      494C010103000400040010001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000001000000001002000000000000010
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      FF00000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000FF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000FF000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000000000FF000000
      FF000000FF000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      00000000FF000000FF000000FF00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000FF000000FF000000FF0000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000000000FF000000
      FF000000FF000000FF0000000000000000000000000000000000000000000000
      0000000000000000FF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF007F7F7F007F7F7F007F7F7F000000000000000000000000000000
      00000000FF000000FF000000FF00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000FF000000FF000000FF0000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      FF000000FF000000FF0000000000000000000000000000000000000000000000
      00000000FF00000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF007F7F7F00FFFFFF00FFFFFF000000000000000000000000000000
      FF000000FF000000FF000000FF000000FF000000000000000000000000000000
      00000000000000000000000000000000000000000000000000000000000000FF
      000000FF000000FF000000FF000000FF00000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000FF000000FF000000FF00000000000000000000000000000000000000
      FF000000FF00000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF007F7F7F00FFFFFF00FFFFFF0000000000000000000000FF000000
      FF000000FF000000FF000000FF000000FF000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000FF000000FF
      000000FF000000FF000000FF000000FF00000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000FF000000FF000000FF0000000000000000000000FF000000
      FF0000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF007F7F7F00FFFFFF00FFFFFF00000000007F7F7F000000FF000000
      FF0000000000000000000000FF000000FF000000FF0000000000000000000000
      000000000000000000000000000000000000000000008080800000FF000000FF
      0000000000000000000000FF000000FF000000FF000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000FF000000FF000000FF000000FF000000FF000000
      0000000000000000000000000000000000007F7F7F00FFFFFF007F7F7F00FFFF
      FF007F7F7F00FFFFFF007F7F7F00FFFFFF007F7F7F00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF007F7F7F00FFFFFF00000000007F7F7F000000FF00000000000000
      00000000000000000000000000000000FF000000FF0000000000000000000000
      0000000000000000000000000000000000008080800000FF0000000000000000
      000000000000000000000000000000FF000000FF000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FF000000FF000000FF00000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF007F7F7F00FFFFFF00FFFFFF000000000000000000000000000000
      00000000000000000000000000000000FF000000FF000000FF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000FF000000FF000000FF0000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000FF000000FF000000FF000000FF000000FF000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF007F7F7F00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000FF000000FF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000FF000000FF0000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000FF000000FF000000FF0000000000000000000000FF000000
      FF0000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF007F7F7F00FFFFFF00FFFFFF000000000000000000000000000000
      000000000000000000000000000000000000000000000000FF000000FF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000FF000000FF00000000
      0000000000000000000000000000000000000000000000000000000000000000
      FF000000FF000000FF000000FF00000000000000000000000000000000000000
      FF000000FF00000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF007F7F7F007F7F7F007F7F7F000000000000000000000000000000
      00000000000000000000000000000000000000000000000000007F7F7F000000
      FF00000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000008080800000FF
      00000000000000000000000000000000000000000000000000000000FF000000
      FF000000FF000000FF0000000000000000000000000000000000000000000000
      00000000FF000000FF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000007F7F
      7F000000FF000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000008080
      800000FF000000000000000000000000000000000000000000000000FF000000
      FF000000FF000000000000000000000000000000000000000000000000000000
      000000000000000000000000FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000FF000000FF00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000FF000000FF0000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00424D3E000000000000003E000000
      2800000040000000100000000100010000000000800000000000000000000000
      000000000000000000000000FFFFFF00FFFFFFFFFFFFFFFFFFFFFFFFEFFD00F8
      F9FFF9FFC7FFFFFFF0FFF0FFC3FBFFFFF0FFF0FFE3F7FFFFE07FE07FF1E700F8
      C07FC07FF8CFFFFF843F843FFC1FFFFF1E3F1E3FFE3FFFFFFE1FFE1FFC1FFFFF
      FF1FFF1FF8CFFFFFFF8FFF8FE1E7FFFFFFC7FFC7C3F3FFFFFFE3FFE3C7FDFFFF
      FFF8FFF8FFFF0000FFFFFFFFFFFF000000000000000000000000000000000000
      000000000000}
  end
  object uqsLetras: TUpdateSQL
    Left = 632
    Top = 86
  end
  object qsSaldoMes: TQuery
    AfterScroll = qsSaldoMesAfterScroll
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select  '
      '(  cast(extract(YEAR  from fecha) as varchar(4) ) || '#39'-'#39' ||'
      '   cast( (case extract(month from vence)'
      '   when 1 then '#39'01'#39
      '   when 2 then '#39'02'#39
      '   when 3 then '#39'03'#39
      '   when 4 then '#39'04'#39
      '   when 5 then '#39'05'#39
      '   when 6 then '#39'06'#39
      '   when 7 then '#39'07'#39
      '   when 8 then '#39'08'#39
      '   when 9 then '#39'09'#39
      '   when 10 then '#39'10'#39
      '   when 11 then '#39'11'#39
      '   when 12 then '#39'12'#39
      '   end) as varchar(2) ) '
      ') as fechax,   '
      'sum(saldo) as SALDO   '
      
        'from movmay2 where mayoris = :Mayoris and saldo > 0.05 and coa =' +
        ' '#39'C'#39' and cia = :Cia'
      'group by fechax')
    Left = 605
    Top = 332
    ParamData = <
      item
        DataType = ftString
        Name = 'Mayoris'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'Cia'
        ParamType = ptUnknown
      end>
  end
  object dtsSaldoMes: TDataSource
    AutoEdit = False
    DataSet = qsSaldoMes
    Left = 645
    Top = 332
  end
  object qry_abonosxmes: TQuery
    AfterScroll = qry_abonosxmesAfterScroll
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select'
      'cast('
      'extract(YEAR  from a.fecha) * 100 + extract(month from a.fecha)'
      'as varchar(6) )'
      'as fechax,'
      'sum(b.importe) as importe'
      'from polcob a'
      'join renpolco b on a.idpolcob = b.idpolcob'
      
        'where a.fecha between :FECHAINI and :FECHAFIN and cliente = :May' +
        'oris'
      'and a.cia = :Cia'
      'group by fechax')
    Left = 605
    Top = 363
    ParamData = <
      item
        DataType = ftDateTime
        Name = 'FECHAINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECHAFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'Mayoris'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'Cia'
        ParamType = ptUnknown
      end>
  end
  object dts_abonosxmes: TDataSource
    AutoEdit = False
    DataSet = qry_abonosxmes
    Left = 645
    Top = 363
  end
  object qry_abonos: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select a.cliente as mayoris, a.folio, a.docto, a.letra as pagare' +
        ', a.numren as conse,'
      'a.fecha, a.concep, '#39'A'#39' as coa, a.importe, a.tipago,'
      'b.vence, b.fecha as fecfac,'
      
        'cast((case b.tipago when '#39'M'#39' then '#39'MERCANCIA'#39' when '#39'I'#39' then '#39'INT' +
        'ERESES'#39' when '#39'O'#39' then '#39'MORATORIOS'#39' end) as varchar(15) ) as sTip' +
        'ago'
      'from renpolco  a'
      
        'join movmay2 b on a.cliente = b.mayoris and a.docto = b.docto an' +
        'd a.letra = b.pagare'
      'and b.coa = '#39'C'#39
      
        'where a.cliente = :Mayoris  and a.fecha between :FECHAINI and :F' +
        'ECHAFIN'
      'and a.folio = :FOLIO and a.cia = :CIA'
      'order by a.fecha, a.numren')
    Left = 202
    Top = 290
    ParamData = <
      item
        DataType = ftString
        Name = 'Mayoris'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECHAINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECHAFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'FOLIO'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'Cia'
        ParamType = ptUnknown
      end>
  end
  object dts_abonos: TDataSource
    DataSet = qry_abonos
    Left = 238
    Top = 291
  end
  object qry_facxmes: TQuery
    AfterScroll = qry_facxmesAfterScroll
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select'
      'cast('
      'extract(YEAR  from fecha) * 100 + extract(month from fecha)'
      'as varchar(6) )'
      'as fechax,'
      'sum(importe) as importe'
      'from facturma a join tipo_facturma b on a.tipofac = b.tipofac'
      
        'where mayoris = :Mayoris and fecha between :FECHAINI and :FECHAF' +
        'IN'
      'and cia = :Cia and mayomen = '#39'Y'#39' and tipofac <> :TIPO_NTC_MAY'
      'group by fechax'
      ''
      ' ')
    Left = 64
    Top = 347
    ParamData = <
      item
        DataType = ftString
        Name = 'Mayoris'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECHAINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECHAFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'Cia'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'TIPO_NTC_MAY'
        ParamType = ptUnknown
      end>
  end
  object dts_facxmes: TDataSource
    AutoEdit = False
    DataSet = qry_facxmes
    Left = 96
    Top = 347
  end
  object dts_edoanu: TDataSource
    AutoEdit = False
    DataSet = qry_edoanu
    Left = 128
    Top = 377
  end
  object qry_edoanu: TQuery
    CachedUpdates = True
    AfterScroll = qry_edoanuAfterScroll
    AutoRefresh = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select'
      'c.descri, a.codigo, a.nombre,'
      'sum( 0 ) as sdoini,'
      'sum ( case coa when '#39'C'#39' then importe else 0 end ) as cargos,'
      'sum ( case coa when '#39'A'#39' then importe else 0 end ) as abonos,'
      
        'sum ( case coa when '#39'C'#39' then importe else 0-importe end ) as net' +
        'o,'
      
        '( select sum(saldo) from movmay2 c where c.mayoris = a.codigo an' +
        'd coa = '#39'C'#39' and saldo >= 1) as saldo'
      
        'from mayoris a join movmay2 b on a.codigo = b.mayoris and a.cia ' +
        '= b.cia'
      'join inv_tipomayoris c on a.tipo = c.idtipomay'
      'where fecha between :FECHAINI and :FECHAFIN and a.cia = :CIA'
      'group by c.descri, a.codigo, a.nombre'
      ' ')
    UpdateObject = uqry_edoanu
    Left = 128
    Top = 347
    ParamData = <
      item
        DataType = ftDateTime
        Name = 'FECHAINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECHAFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'Cia'
        ParamType = ptUnknown
      end>
  end
  object qry_pronost: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select '
      'mayoris, a.nombre,'
      'sum ( case coa when '#39'C'#39' then importe else 0 end ) as cargos,'
      'sum ( case coa when '#39'A'#39' then importe else 0 end ) as abonos,'
      
        'sum ( case coa when '#39'C'#39' then importe else 0-importe end ) as net' +
        'o,'
      'sum ( 0*1 ) as antvenc,'
      'sum ( 0*1 ) as nvovenc,'
      'sum ( 0*1 ) as venctot,'
      'sum ( 0*1 ) as porvenc,'
      'sum ( 0*1 ) as pagoantven,'
      'sum ( 0*1 ) as pagonvoven,'
      'sum ( 0*1 ) as abonoesp,'
      'sum ( 0*1 ) as exigible,'
      'sum ( 0*1 ) as porcen,'
      'sum ( 0*1 ) as porglo'
      
        'from mayoris a join movmay2 b on a.codigo = b.mayoris and a.cia ' +
        '= b.cia'
      'where fecha between :FECHAINI and :FECHAFIN and a.cia = :CIA'
      'group by mayoris, a.nombre'
      ' ')
    UpdateObject = uqry_pronost
    Left = 191
    Top = 347
    ParamData = <
      item
        DataType = ftDateTime
        Name = 'FECHAINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECHAFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'Cia'
        ParamType = ptUnknown
      end>
  end
  object dts_pronost: TDataSource
    DataSet = qry_pronost
    Left = 223
    Top = 347
  end
  object uqry_pronost: TUpdateSQL
    Left = 258
    Top = 347
  end
  object qry_vencs: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select   FECHA, COMPRAS, ABONOS, DEVOLS, SDOFIN, CIA, MAYORIS, B' +
        'ONIF, VENCANT,'
      '   VENCREC, PORVENC, COBINTERNA, CARTERA'
      'from edomay'
      'where mayoris = :MAYORIS and fecha = :FECHA and cia = :CIA'
      ' ')
    UpdateObject = uqry_vencs
    Left = 288
    Top = 347
    ParamData = <
      item
        DataType = ftString
        Name = 'MAYORIS'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECHA'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'Cia'
        ParamType = ptUnknown
      end>
  end
  object ActionList1: TActionList
    Images = dm.ImageList1
    Left = 388
    Top = 212
    object exporta_dbgrid: TAction
      Caption = 'Exportar...'
      ImageIndex = 19
      OnExecute = exporta_dbgridExecute
    end
    object impri_graph: TAction
      Caption = 'Imprimir'
      ImageIndex = 21
      OnExecute = impri_graphExecute
    end
    object graba_bitmap: TAction
      Caption = 'Exportar a Imagen'
      ImageIndex = 9
      OnExecute = graba_bitmapExecute
    end
    object desp_datos_may: TAction
      Caption = 'Despliega Datos Mayoris'
      ImageIndex = 27
      OnExecute = desp_datos_mayExecute
    end
    object WindowClose1: TWindowClose
      Category = 'Window'
      Caption = '&Salir'
      ImageIndex = 3
    end
    object consulta_factura: TAction
      Caption = 'Factura'
      ImageIndex = 23
      OnExecute = consulta_facturaExecute
    end
    object observs_may: TAction
      Caption = 'Observaciones Mayoreo'
      ImageIndex = 27
      OnExecute = observs_mayExecute
    end
    object ver_permisiones: TAction
      Caption = 'Permisiones'
      OnExecute = ver_permisionesExecute
    end
  end
  object PopupMenu1: TPopupMenu
    Left = 428
    Top = 128
    object Exportar1: TMenuItem
      Action = exporta_dbgrid
    end
  end
  object qry_consmay: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select a.mayoris, a.docto, a.pagare, a.conse, a.fecha, a.concep,' +
        ' a.coa, a.importe, a.tipago,'
      'b.vence, b.fecha as fecfac,'
      
        'cast((case b.tipago when '#39'M'#39' then '#39'MERCANCIA'#39' when '#39'I'#39' then '#39'INT' +
        'ERESES'#39' when '#39'O'#39' then '#39'MORATORIOS'#39' end) as varchar(15) ) as sTip' +
        'ago,'
      
        'cast( extract(YEAR  from a.fecha) * 100 + extract(month from a.f' +
        'echa) as varchar(6) ) as fech,'
      
        'cast((a.mayoris || cast(a.docto as varchar(12) ) || cast(a.pagar' +
        'e as varchar(6) ) ) as varchar(25) ) as sLlave'
      'from movmay2 a'
      
        'join movmay2 b on a.mayoris = b.mayoris and a.docto = b.docto an' +
        'd a.pagare = b.pagare'
      'and b.coa = '#39'C'#39
      
        'where a.mayoris = :Mayoris  and a.fecha between :FECHAINI and :F' +
        'ECHAFIN'
      'and a.coa = '#39'A'#39' and a.cia = :CIA'
      'order by a.fecha'
      ''
      ' ')
    Left = 202
    Top = 258
    ParamData = <
      item
        DataType = ftString
        Name = 'Mayoris'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECHAINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECHAFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'Cia'
        ParamType = ptUnknown
      end>
  end
  object dts_consmay: TDataSource
    AutoEdit = False
    DataSet = qry_consmay
    Left = 238
    Top = 259
  end
  object qry_compraspagosxmes: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select'
      'mayoris,'
      'cast ( extract(YEAR  from fecha) as integer) as anu,'
      'cast ( extract(MONTH from fecha) as integer) as mes,'
      'sum ( case coa when '#39'C'#39' then importe else 0 end ) as cargos,'
      'sum ( case coa when '#39'A'#39' then importe else 0 end ) as abonos'
      'from movmay2'
      
        'where mayoris = :MAYORIS and fecha between :FECHAINI and :FECHAF' +
        'IN and cia = :CIA'
      'group by mayoris, anu, mes')
    Left = 160
    Top = 349
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'MAYORIS'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECHAINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECHAFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'Cia'
        ParamType = ptUnknown
      end>
  end
  object dts_compraspagosxmes: TDataSource
    AutoEdit = False
    DataSet = qry_compraspagosxmes
    Left = 160
    Top = 377
  end
  object PopupMenuGraf: TPopupMenu
    Left = 470
    Top = 211
    object imprigraph1: TMenuItem
      Action = impri_graph
    end
    object ExportaraBitmap1: TMenuItem
      Action = graba_bitmap
    end
    object Permisiones1: TMenuItem
      Action = ver_permisiones
    end
  end
  object uqry_vencs: TUpdateSQL
    ModifySQL.Strings = (
      'update edomay'
      'set'
      '  FECHA = :FECHA,'
      '  COMPRAS = :COMPRAS,'
      '  ABONOS = :ABONOS,'
      '  DEVOLS = :DEVOLS,'
      '  SDOFIN = :SDOFIN,'
      '  CIA = :CIA,'
      '  MAYORIS = :MAYORIS,'
      '  BONIF = :BONIF,'
      '  VENCANT = :VENCANT,'
      '  VENCREC = :VENCREC,'
      '  PORVENC = :PORVENC,'
      '  COBINTERNA = :COBINTERNA,'
      '  CARTERA = :CARTERA'
      'where'
      '  FECHA = :OLD_FECHA and'
      '  CIA = :OLD_CIA and'
      '  MAYORIS = :OLD_MAYORIS')
    InsertSQL.Strings = (
      'insert into edomay'
      '  (FECHA, COMPRAS, ABONOS, DEVOLS, SDOFIN, CIA, MAYORIS, BONIF, '
      'VENCANT, '
      '   VENCREC, PORVENC, COBINTERNA, CARTERA)'
      'values'
      
        '  (:FECHA, :COMPRAS, :ABONOS, :DEVOLS, :SDOFIN, :CIA, :MAYORIS, ' +
        ':BONIF, '
      '   :VENCANT, :VENCREC, :PORVENC, :COBINTERNA, :CARTERA)')
    DeleteSQL.Strings = (
      'delete from edomay'
      'where'
      '  FECHA = :OLD_FECHA and'
      '  CIA = :OLD_CIA and'
      '  MAYORIS = :OLD_MAYORIS')
    Left = 286
    Top = 377
  end
  object qry_pendpagglob: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select a.mayoris, a.docto, a.pagare, a.conse, a.fecha, a.concep,' +
        ' a.coa, a.importe, a.tipago,'
      'b.vence, b.fecha as fecfac,'
      
        'cast((case b.tipago when '#39'M'#39' then '#39'MERCANCIA'#39' when '#39'I'#39' then '#39'INT' +
        'ERESES'#39' when '#39'O'#39' then '#39'MORATORIOS'#39' end) as varchar(15) ) as sTip' +
        'ago,'
      
        'cast( extract(YEAR  from a.fecha) * 100 + extract(month from a.f' +
        'echa) as varchar(6) ) as fech,'
      
        'cast((a.mayoris || cast(a.docto as varchar(12) ) || cast(a.pagar' +
        'e as varchar(6) ) ) as varchar(25) ) as sLlave'
      'from movmay2 a'
      
        'join movmay2 b on a.mayoris = b.mayoris and a.docto = b.docto an' +
        'd a.pagare = b.pagare'
      'and b.coa = '#39'C'#39
      
        'where a.mayoris = :Mayoris  and a.fecha between :FECHAINI and :F' +
        'ECHAFIN'
      'and a.coa = '#39'A'#39' and a.cia = :CIA'
      'order by a.fecha'
      '')
    Left = 274
    Top = 290
    ParamData = <
      item
        DataType = ftString
        Name = 'Mayoris'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECHAINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECHAFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'Cia'
        ParamType = ptUnknown
      end>
  end
  object qry_aboxtipo: TQuery
    CachedUpdates = True
    AfterScroll = qry_aboxtipoAfterScroll
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select a.cliente as mayoris, a.fecha, a.folio,'
      'sum ( 0 ) as merc,'
      'sum ( 0 ) as dev,'
      'sum ( 0 ) as bon,'
      'sum ( 0 ) as interes,'
      'sum ( 0 ) as mora,'
      'sum ( a.importe) as total,'
      'sum ( 0 ) as acum'
      'from renpolco a'
      
        'where a.cliente= :MAYORIS and a.fecha between :FECINI and :FECFI' +
        'N'
      'and a.cia = :CIA'
      'group by a.cliente, a.fecha, a.folio'
      ' '
      ' '
      ' '
      ' ')
    UpdateObject = uqry_aboxtipo
    Left = 202
    Top = 320
    ParamData = <
      item
        DataType = ftString
        Name = 'Mayoris'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'Cia'
        ParamType = ptUnknown
      end>
  end
  object dts_aboxtipo: TDataSource
    DataSet = qry_aboxtipo
    Left = 238
    Top = 321
  end
  object uqry_aboxtipo: TUpdateSQL
    Left = 273
    Top = 321
  end
  object qry_abonomesxtipo: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select a.cliente, a.fecha, a.folio, a.tipago, b.tipago as tipcom' +
        'pra,'
      'sum ( a.importe) as imp'
      'from renpolco a'
      'join movmay2 b on a.cliente = b.mayoris and a.docto = b.docto'
      'and a.letra = b.pagare and a.tipofac = b.tipofac and b.coa = '#39'C'#39
      'where a.cliente = :MAYORIS'
      'and a.fecha between :FECINI and :FECFIN and a.cia = :CIA'
      'group by a.cliente, a.fecha, a.folio, a.tipago, b.tipago'
      ''
      '')
    Left = 306
    Top = 320
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'MAYORIS'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'FECINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'FECFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_facxmesglo: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select'
      'cast('
      'extract(YEAR  from fecha) * 100 + extract(month from fecha)'
      'as varchar(6) )'
      'as fechax,'
      'sum(importe * b.signo) as importe'
      'from facturma a join tipo_facturma b on a.tipofac = b.tipofac'
      'where fecha between :FECHAINI and :FECHAFIN'
      'and cia = :Cia and mayomen = '#39'Y'#39
      'group by fechax')
    Left = 64
    Top = 379
    ParamData = <
      item
        DataType = ftDateTime
        Name = 'FECHAINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECHAFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'Cia'
        ParamType = ptUnknown
      end>
  end
  object dts_facxmesglo: TDataSource
    AutoEdit = False
    DataSet = qry_facxmesglo
    Left = 96
    Top = 379
  end
  object qry_mayoristas: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select'
      'codigo, nombre, direc, ciu, rfc, tel, cargos, abonos, compraanu,'
      'comprames, pdsc, ultmov, status, cia, nompag1, nompag2, dirpag1,'
      'dirpag2, ciupag, nombre2'
      'from mayoris where cia = :CIA order by codigo'
      ' ')
    Left = 380
    Top = 330
    ParamData = <
      item
        DataType = ftInteger
        Name = 'Cia'
        ParamType = ptUnknown
      end>
  end
  object dts_mayoristas: TDataSource
    DataSet = qry_mayoristas
    Left = 380
    Top = 360
  end
  object uqry_edoanu: TUpdateSQL
    Left = 127
    Top = 406
  end
  object dts_pendpagglob: TDataSource
    DataSet = qry_pendpagglob
    Left = 306
    Top = 292
  end
  object uqry_qsPendPag: TUpdateSQL
    Left = 128
    Top = 273
  end
  object uqry_facturas: TUpdateSQL
    Left = 32
    Top = 289
  end
  object qry_mayrelac: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select a.idrelac, a.idmayoris, a.mayoris, a.idtiporel, a.iddato1' +
        ', a.iddato2, a.cia,'
      'b.descri as tipotel, c.telfax'
      'from may_relac a join may_tipostel b on a.iddato1 = b.idtipotel'
      'join telfax c on a.iddato2 = c.idtel'
      'where a.mayoris = :MAYORIS and a.cia = :CIA')
    Left = 411
    Top = 359
    ParamData = <
      item
        DataType = ftString
        Name = 'MAYORIS'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_mayrelac: TDataSource
    AutoEdit = False
    DataSet = qry_mayrelac
    Left = 410
    Top = 332
  end
  object qry_edoanuant: TQuery
    CachedUpdates = True
    AfterScroll = qry_edoanuAfterScroll
    AutoRefresh = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select mayoris, b.nombre, sdofin, c.descri from edomay a'
      'join mayoris b on a.mayoris = b.codigo and a.cia = b.cia'
      'join inv_tipomayoris c on b.tipo = c.idtipomay'
      'where fecha = :FECHAFINANUANT and sdofin > .05'
      'and a.cia = :CIA order by mayoris')
    Left = 192
    Top = 379
    ParamData = <
      item
        DataType = ftDateTime
        Name = 'FECHAFINANUANT'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'Cia'
        ParamType = ptUnknown
      end>
  end
  object qry_edoanu2: TQuery
    CachedUpdates = True
    AutoRefresh = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select'
      'c.descri, a.codigo, a.nombre,'
      'sum( 0 ) as sdoini,'
      'sum ( case coa when '#39'C'#39' then importe else 0 end ) as cargos,'
      'sum ( case coa when '#39'A'#39' then importe else 0 end ) as abonos,'
      
        'sum ( case coa when '#39'C'#39' then importe else 0-importe end ) as net' +
        'o,'
      
        '( select sum(saldo) from movmay2 c where c.mayoris = a.codigo an' +
        'd coa = '#39'C'#39' and saldo >= 1) as saldo'
      
        'from mayoris a join movmay2 b on a.codigo = b.mayoris and a.cia ' +
        '= b.cia'
      'join inv_tipomayoris c on a.tipo = c.idtipomay'
      'where fecha between :FECHAINI and :FECHAFIN and a.cia = :CIA'
      'group by c.descri, a.codigo, a.nombre'
      ' ')
    UpdateObject = uqry_edoanu2
    Left = 32
    Top = 451
    ParamData = <
      item
        DataType = ftDateTime
        Name = 'FECHAINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECHAFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'Cia'
        ParamType = ptUnknown
      end>
  end
  object dts_edoanu2: TDataSource
    AutoEdit = False
    DataSet = qry_edoanu2
    Left = 32
    Top = 481
  end
  object uqry_edoanu2: TUpdateSQL
    Left = 31
    Top = 510
  end
  object dts_observs: TDataSource
    AutoEdit = False
    DataSet = qry_observs
    Left = 163
    Top = 440
  end
  object qry_observs: TQuery
    AutoRefresh = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      
        'select * from observent where tipo= :TIPOOBS and alm = :ALM and ' +
        'codigo = :CODIGO and cia = :CIA and numero = :NUMERO'
      'order by fecha desc, conse')
    Left = 166
    Top = 409
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'TIPOOBS'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'ALM'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'NUMERO'
        ParamType = ptUnknown
      end>
  end
end

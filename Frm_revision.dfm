object Form_revision: TForm_revision
  Left = 282
  Top = 201
  Width = 696
  Height = 480
  Caption = 'Form_revision'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poDefault
  Visible = True
  WindowState = wsMaximized
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel6: TPanel
    Left = 0
    Top = 0
    Width = 688
    Height = 40
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Label21: TLabel
      Left = 8
      Top = 12
      Width = 25
      Height = 13
      Caption = 'Inicia'
    end
    object Label22: TLabel
      Left = 152
      Top = 12
      Width = 38
      Height = 13
      Caption = 'Termina'
    end
    object date_fentini: TDateTimePicker
      Left = 40
      Top = 8
      Width = 100
      Height = 21
      CalAlignment = dtaLeft
      Date = 37950.5459288194
      Time = 37950.5459288194
      DateFormat = dfShort
      DateMode = dmComboBox
      Kind = dtkDate
      ParseInput = False
      TabOrder = 0
    end
    object date_fentfin: TDateTimePicker
      Left = 196
      Top = 8
      Width = 100
      Height = 21
      CalAlignment = dtaLeft
      Date = 37950.5459288194
      Time = 37950.5459288194
      DateFormat = dfShort
      DateMode = dmComboBox
      Kind = dtkDate
      ParseInput = False
      TabOrder = 1
    end
    object btn_revisa: TButton
      Left = 312
      Top = 8
      Width = 75
      Height = 25
      Caption = 'Ok'
      TabOrder = 2
      OnClick = btn_revisaClick
    end
  end
  object sgrd_pendtes: TAdvStringGrid
    Left = 0
    Top = 40
    Width = 688
    Height = 413
    Align = alClient
    ColCount = 6
    DefaultColWidth = 40
    DefaultRowHeight = 21
    FixedCols = 0
    RowCount = 3
    FixedRows = 1
    TabOrder = 1
    Bands.Active = True
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
    ScrollWidth = 16
    ScrollSynch = False
    ScrollProportional = False
    ScrollHints = shNone
    OemConvert = False
    FixedFooters = 0
    FixedRightCols = 0
    FixedColWidth = 33
    FixedRowHeight = 21
    FixedFont.Charset = DEFAULT_CHARSET
    FixedFont.Color = clWindowText
    FixedFont.Height = -11
    FixedFont.Name = 'MS Sans Serif'
    FixedFont.Style = []
    FixedAsButtons = False
    FloatFormat = '%.2f'
    WordWrap = False
    ColumnHeaders.Strings = (
      'Tipo'
      'Alm'
      'Num'
      'Codigo'
      'Folio')
    Lookup = False
    LookupCaseSensitive = False
    LookupHistory = False
    BackGround.Top = 0
    BackGround.Left = 0
    BackGround.Display = bdTile
    BackGround.Cells = bcNormal
    Filter = <>
    ColWidths = (
      33
      40
      40
      111
      40
      414)
    RowHeights = (
      21
      21
      21)
  end
  object qry_revision: TQuery
    AutoRefresh = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select a.tipo, a.alm, a.numero, b.codinv, b.folsal, b.folent, b.' +
        'entosal'
      
        'from entradas a join renentra b on a.tipo = b.tipo and a.numero ' +
        '= b.numero '
      'and a.alm = b.alm and a.cia=b.cia'
      'where a.fecha between :FECINI and :FECFIN and a.status = '#39'C'#39
      'and a.tipo <> '#39'G'#39' and a.tipo <> '#39'B'#39
      'order by a.tipo, a.alm, a.numero, b.codinv')
    Left = 464
    Top = 352
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'FECINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'FECFIN'
        ParamType = ptUnknown
      end>
  end
  object qry_movto: TQuery
    AutoRefresh = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select almac, codigo, folio, serie, fecha, fechasal, salio from ' +
        'movart'
      'where codigo = :CODIGO and almac = :ALM and folio = :FOLIO')
    Left = 496
    Top = 352
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'ALM'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'FOLIO'
        ParamType = ptUnknown
      end>
  end
end

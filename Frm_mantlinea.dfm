object Form_mantlinea: TForm_mantlinea
  Left = 306
  Top = 218
  Width = 855
  Height = 385
  Caption = 'Mantenimiento de Lineas Inven'
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
  object Splitter1: TSplitter
    Left = 245
    Top = 29
    Width = 3
    Height = 317
    Cursor = crHSplit
    Align = alRight
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 839
    Height = 29
    Caption = 'ToolBar1'
    Images = dm.ImageList1
    TabOrder = 0
    object tbtn_nuevo: TToolButton
      Left = 0
      Top = 2
      Action = nuevo
    end
    object tbtn_modif: TToolButton
      Left = 23
      Top = 2
      Action = modifica
    end
    object tbtn_borra: TToolButton
      Left = 46
      Top = 2
      Action = borra
    end
    object ToolButton7: TToolButton
      Left = 69
      Top = 2
      Action = grabar
    end
    object ToolButton8: TToolButton
      Left = 92
      Top = 2
      Action = cancelar
    end
    object ToolButton1: TToolButton
      Left = 115
      Top = 2
      Action = WindowClose1
    end
    object ToolButton3: TToolButton
      Left = 138
      Top = 2
      Width = 8
      Caption = 'ToolButton3'
      ImageIndex = 5
      Style = tbsSeparator
    end
  end
  object Panel2: TPanel
    Left = 248
    Top = 29
    Width = 591
    Height = 317
    Align = alRight
    BevelOuter = bvNone
    TabOrder = 1
    object GroupBox1: TGroupBox
      Left = 0
      Top = 0
      Width = 591
      Height = 65
      Align = alTop
      TabOrder = 0
      object Label1: TLabel
        Left = 9
        Top = 11
        Width = 28
        Height = 13
        Caption = '&Línea'
      end
      object Label2: TLabel
        Left = 90
        Top = 11
        Width = 56
        Height = 13
        Caption = '&Descripción'
        FocusControl = edt_nombre
      end
      object Label3: TLabel
        Left = 9
        Top = 35
        Width = 29
        Height = 13
        Caption = 'Orden'
      end
      object Label4: TLabel
        Left = 129
        Top = 35
        Width = 34
        Height = 13
        Caption = 'Región'
      end
      object edt_nombre: TdxEdit
        Left = 169
        Top = 8
        Width = 280
        TabOrder = 1
        CharCase = ecUpperCase
        MaxLength = 30
        StoredValues = 2
      end
      object edt_ptovta: TEdit
        Left = 46
        Top = 8
        Width = 40
        Height = 21
        CharCase = ecUpperCase
        MaxLength = 4
        TabOrder = 0
      end
      object edt_ordlin: TdxCurrencyEdit
        Left = 46
        Top = 32
        Width = 40
        TabOrder = 2
        Alignment = taRightJustify
        DecimalPlaces = 0
        DisplayFormat = '0;-0'
        StoredValues = 1
      end
      object edt_region: TdxEdit
        Left = 169
        Top = 32
        Width = 40
        TabOrder = 3
        CharCase = ecUpperCase
        MaxLength = 1
        StoredValues = 2
      end
    end
    object GroupBox2: TGroupBox
      Left = 0
      Top = 65
      Width = 591
      Height = 252
      Align = alClient
      Caption = 'Observaciones '
      TabOrder = 1
      object Panel1: TPanel
        Left = 2
        Top = 211
        Width = 587
        Height = 39
        Align = alBottom
        BevelOuter = bvNone
        TabOrder = 0
        object BitBtn1: TBitBtn
          Left = 48
          Top = 8
          Width = 120
          Height = 25
          Action = agregaobs
          Caption = 'Agregar Renglón'
          TabOrder = 0
          Glyph.Data = {
            36040000424D3604000000000000360000002800000010000000100000000100
            2000000000000004000000000000000000000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF000000FF000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00000000000000000000000000FF00FF00FF00
            FF00FF00FF000000FF000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00000000000000000000000000FF00FF000000
            FF000000FF000000FF000000FF000000FF000000FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF000000
            FF000000FF000000FF000000FF000000FF000000FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
            FF00FF00FF000000FF000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
            FF00FF00FF000000FF000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF000000FF000000FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            0000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF00
            0000FF000000FF00FF000000FF000000FF00FF00FF00FF00FF00FF00FF00FF00
            0000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF00
            0000FF000000FF00FF000000FF000000FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF000000FF000000FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00000000000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00000000000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00}
        end
        object BitBtn2: TBitBtn
          Left = 191
          Top = 7
          Width = 120
          Height = 25
          Action = borraobs
          Caption = 'Borrar renglón'
          TabOrder = 1
          Glyph.Data = {
            36040000424D3604000000000000360000002800000010000000100000000100
            2000000000000004000000000000000000000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00000000000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00000000000000000000000000FF00FF000000
            FF000000FF000000FF000000FF000000FF000000FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF000000
            FF000000FF000000FF000000FF000000FF000000FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
            FF00FF00FF00FF000000FF000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            0000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF00
            0000FF000000FF00FF000000FF000000FF00FF00FF00FF00FF00FF00FF00FF00
            0000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF00
            0000FF000000FF00FF000000FF000000FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF000000FF000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00000000000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00000000000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00}
        end
        object BitBtn3: TBitBtn
          Left = 333
          Top = 7
          Width = 120
          Height = 25
          Action = modifren
          Caption = 'Modifica Renglon'
          TabOrder = 2
          Glyph.Data = {
            42020000424D4202000000000000420000002800000010000000100000000100
            1000030000000002000000000000000000000000000000000000007C0000E003
            00001F0000001F7C1F7C1F7C1F7C1F7C1F7C0000000000000000000000000000
            0000000000001F7C1F7C1F7C1F7C1F7C1F7C0000FF7FFF7FFF7FFF7FFF7FFF7F
            FF7FFF7F0000000000001F7C00000000000000000000FF7FFF7F0000FF7F0000
            0000FF7F0000FF0300000000E07FFF7FE07FFF7FE07F0000FF7FFF7FFF7FFF7F
            FF7FFF7F0000FF030000E07FFF7FE07FFF7F000000000000FF7FFF7FFF7FFF7F
            0000FF7F0000FF030000FF7FE07FFF7FE07FFF7FE07FFF7F0000FF7F00000000
            FF7FFF7F0000FF030000E07FFF7FE07FFF7F00000000000000000000E07F0000
            FF7FFF7F0000FF030000FF7FE07FFF7FE07FFF7FE07FFF7FE07FFF7F0000FF7F
            FF7FFF7F0000FF030000E07FFF7F0000000000000000000000000000FF7FFF7F
            FF7FFF7F0000000000000000E07FFF7FE07F00000000E07F0000FF7FFF7F0000
            0000FF7F00001F7C1F7C1F7C0000000000000000E07F0000FF7FFF7FFF7FFF7F
            FF7FFF7F00001F7C1F7C1F7C1F7C1F7C0000E07F0000FF7FFF7FFF7FFF7F0000
            0000000000001F7C1F7C1F7C1F7C0000E07F0000FF7FFF7F00000000FF7F0000
            FF7FFF7F00001F7C1F7C1F7C0000E07F00000000FF7FFF7FFF7FFF7FFF7F0000
            FF7F00001F7C1F7C1F7C0000007C00001F7C0000FF7FFF7FFF7FFF7FFF7F0000
            00001F7C1F7C1F7C1F7C1F7C00001F7C1F7C0000000000000000000000000000
            1F7C1F7C1F7C}
        end
        object BitBtn4: TBitBtn
          Left = 461
          Top = 7
          Width = 120
          Height = 25
          Action = borratodasobs
          Caption = 'Borrar Renglones'
          TabOrder = 3
          Glyph.Data = {
            36040000424D3604000000000000360000002800000010000000100000000100
            2000000000000004000000000000000000000000000000000000FF00FF00FF00
            FF00FF00FF000000000000000000000000000000000000000000000000000000
            00000000000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF0000000000FFFFFF007F7F7F007F7F7F007F7F7F007F7F7F007F7F
            7F007F7F7F0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF0000000000FFFFFF00FFFFFF0000000000BFBFBF0000000000BFBFBF000000
            00007F7F7F007F7F7F0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF0000000000FFFFFF00FFFFFF0000000000BFBFBF00000000007F7F7F000000
            00007F7F7F007F7F7F0000000000FF00FF00FF00FF00FF00FF00FF00FF000000
            0000FFFFFF00FFFFFF007F7F7F007F7F7F00BFBFBF0000000000BFBFBF007F7F
            7F00000000007F7F7F007F7F7F0000000000FF00FF00FF00FF00FF00FF000000
            0000FFFFFF00FFFFFF0000000000BFBFBF00BFBFBF00000000007F7F7F00BFBF
            BF00000000007F7F7F007F7F7F0000000000FF00FF0000000000000000000000
            0000FFFFFF00FFFFFF0000000000BFBFBF00BFBFBF0000000000BFBFBF007F7F
            7F00000000007F7F7F007F7F7F000000000000000000FF00FF00FF00FF000000
            0000FFFFFF00FFFFFF007F7F7F007F7F7F00BFBFBF00000000007F7F7F00BFBF
            BF00000000007F7F7F007F7F7F0000000000FF00FF00FF00FF00FF00FF00FF00
            FF0000000000FFFFFF00FFFFFF0000000000BFBFBF0000000000BFBFBF000000
            00007F7F7F007F7F7F0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF0000000000FFFFFF00FFFFFF0000000000BFBFBF00000000007F7F7F000000
            00007F7F7F007F7F7F0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00000000000000000000000000000000000000000000000000000000000000
            0000000000000000000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF0000000000FFFFFF00BFBFBF00BFBFBF00BFBFBF007F7F7F007F7F7F007F7F
            7F007F7F7F007F7F7F0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00000000000000000000000000000000000000000000000000000000000000
            0000000000000000000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00000000007F7F7F007F7F7F007F7F7F000000
            0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00000000000000000000000000000000000000
            0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00}
        end
      end
      object page_observs: TPageControl
        Left = 2
        Top = 15
        Width = 587
        Height = 196
        ActivePage = tbs_mds
        Align = alClient
        TabOrder = 1
        object tbs_mds: TTabSheet
          Caption = 'MDS'
          object dbgrd_obsmds: TdxDBGrid
            Left = 0
            Top = 0
            Width = 579
            Height = 168
            Bands = <
              item
              end>
            DefaultLayout = True
            HeaderPanelRowCount = 1
            KeyField = 'CONSE'
            SummaryGroups = <>
            SummarySeparator = ', '
            Align = alClient
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Lucida Console'
            Font.Style = []
            ParentFont = False
            TabOrder = 0
            OnKeyDown = dbgrd_obsmdsKeyDown
            BandFont.Charset = DEFAULT_CHARSET
            BandFont.Color = clWindowText
            BandFont.Height = -11
            BandFont.Name = 'MS Sans Serif'
            BandFont.Style = []
            DataSource = dts_obslinmds
            Filter.Criteria = {00000000}
            HeaderFont.Charset = DEFAULT_CHARSET
            HeaderFont.Color = clWindowText
            HeaderFont.Height = -11
            HeaderFont.Name = 'MS Sans Serif'
            HeaderFont.Style = []
            OptionsDB = [edgoCancelOnExit, edgoCanInsert, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoSyncSelection, edgoUseBookmarks, edgoUseLocate]
            OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
            PreviewFont.Charset = DEFAULT_CHARSET
            PreviewFont.Color = clBlue
            PreviewFont.Height = -11
            PreviewFont.Name = 'MS Sans Serif'
            PreviewFont.Style = []
            object dbgrd_obsmdsORDEN: TdxDBGridMaskColumn
              Caption = 'Orden'
              Width = 44
              BandIndex = 0
              RowIndex = 0
              FieldName = 'CONSE'
            end
            object dbgrd_obsmdsOBSER: TdxDBGridMaskColumn
              Caption = 'Observaciones'
              Width = 479
              BandIndex = 0
              RowIndex = 0
              FieldName = 'OBSER'
            end
            object dbgrd_obsmdsFONINI: TdxDBGridMaskColumn
              Caption = 'F.Ini'
              Width = 29
              BandIndex = 0
              RowIndex = 0
              FieldName = 'FONINI'
            end
            object dbgrd_obsmdsFONFIN: TdxDBGridMaskColumn
              Caption = 'F.Fin'
              Width = 29
              BandIndex = 0
              RowIndex = 0
              FieldName = 'FONFIN'
            end
          end
        end
      end
    end
  end
  object dxDBGrid1: TdxDBGrid
    Left = 0
    Top = 29
    Width = 245
    Height = 317
    Bands = <
      item
      end>
    DefaultLayout = True
    HeaderPanelRowCount = 1
    KeyField = 'IDLINEA'
    SummaryGroups = <>
    SummarySeparator = ', '
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Lucida Console'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnKeyDown = dbgrd_obsmdsKeyDown
    BandFont.Charset = DEFAULT_CHARSET
    BandFont.Color = clWindowText
    BandFont.Height = -11
    BandFont.Name = 'MS Sans Serif'
    BandFont.Style = []
    DataSource = dts_lineas
    Filter.Criteria = {00000000}
    HeaderFont.Charset = DEFAULT_CHARSET
    HeaderFont.Color = clWindowText
    HeaderFont.Height = -11
    HeaderFont.Name = 'MS Sans Serif'
    HeaderFont.Style = []
    OptionsDB = [edgoCancelOnExit, edgoCanInsert, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoSyncSelection, edgoUseBookmarks, edgoUseLocate]
    OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
    PreviewFont.Charset = DEFAULT_CHARSET
    PreviewFont.Color = clBlue
    PreviewFont.Height = -11
    PreviewFont.Name = 'MS Sans Serif'
    PreviewFont.Style = []
    object dxDBGrid1LINEA: TdxDBGridMaskColumn
      Caption = 'Línea'
      BandIndex = 0
      RowIndex = 0
      FieldName = 'LINEA'
    end
    object dxDBGrid1DESCRI: TdxDBGridMaskColumn
      Caption = 'Descripción'
      BandIndex = 0
      RowIndex = 0
      FieldName = 'DESCRI'
    end
    object dxDBGrid1ORDEN: TdxDBGridMaskColumn
      Caption = 'Orden'
      BandIndex = 0
      RowIndex = 0
      FieldName = 'ORDEN'
    end
    object dxDBGrid1REGION: TdxDBGridMaskColumn
      Caption = 'Región'
      BandIndex = 0
      RowIndex = 0
      FieldName = 'REGION'
    end
  end
  object qry_lineas: TQuery
    CachedUpdates = True
    AfterScroll = qry_lineasAfterScroll
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select idlinea, linea, descri, orden, region, cia '
      'from inv_lineas where cia = :CIA'
      'order by linea')
    UpdateObject = uqry_lineas
    Left = 344
    Top = 192
    ParamData = <
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object uqry_lineas: TUpdateSQL
    ModifySQL.Strings = (
      'update inv_lineas'
      'set'
      '  DESCRI = :DESCRI,'
      '  ORDEN = :ORDEN,'
      '  REGION = :REGION'
      'where'
      '  IDLINEA = :OLD_IDLINEA')
    InsertSQL.Strings = (
      'insert into inv_lineas'
      '  (IDLINEA, LINEA, DESCRI, ORDEN, REGION, CIA)'
      'values'
      '  (:IDLINEA, :LINEA, :DESCRI, :ORDEN, :REGION, :CIA)')
    DeleteSQL.Strings = (
      'delete from inv_lineas'
      'where'
      '  IDLINEA = :OLD_IDLINEA')
    Left = 342
    Top = 160
  end
  object ActionList1: TActionList
    Images = dm.ImageList1
    Left = 280
    Top = 192
    object nuevo: TAction
      Caption = '&Nuevo'
      ImageIndex = 0
      ShortCut = 16462
      OnExecute = nuevoExecute
    end
    object modifica: TAction
      Caption = '&Modifica'
      Hint = 'Modifica'
      ImageIndex = 1
      ShortCut = 16461
      OnExecute = modificaExecute
    end
    object borra: TAction
      Caption = 'Borra'
      Hint = 'Borra'
      ImageIndex = 2
      ShortCut = 16450
      OnExecute = borraExecute
    end
    object grabar: TAction
      Caption = 'Grabar'
      Enabled = False
      ImageIndex = 9
      ShortCut = 16455
    end
    object cancelar: TAction
      Caption = 'Cancelar'
      Enabled = False
      ImageIndex = 11
      ShortCut = 16460
      OnExecute = cancelarExecute
    end
    object WindowClose1: TWindowClose
      Category = 'Window'
      Caption = 'C&lose'
      ImageIndex = 3
    end
    object primero: TAction
      Caption = 'primero'
      Hint = 'Selecciona la Primer Marca'
      ImageIndex = 5
      ShortCut = 49232
      OnExecute = primeroExecute
    end
    object anterior: TAction
      Caption = 'Anterior'
      Hint = 'Selecciona la Anterior Marca'
      ImageIndex = 6
      ShortCut = 49217
      OnExecute = anteriorExecute
    end
    object siguiente: TAction
      Caption = 'Siguiente'
      Hint = 'Selecciona la Siguiente Marca'
      ImageIndex = 8
      ShortCut = 49235
      OnExecute = siguienteExecute
    end
    object ultimo: TAction
      Caption = 'Ultimo'
      Hint = 'Selecciona la Ultima Marca'
      ImageIndex = 7
      ShortCut = 49237
      OnExecute = ultimoExecute
    end
    object agregaobs: TAction
      Caption = 'Agregar Renglón'
      Hint = 'Agrega una línea de observaciones'
      ImageIndex = 13
      OnExecute = agregaobsExecute
    end
    object borraobs: TAction
      Caption = 'Borrar renglón'
      Hint = 'Borra la línea de observaciones que tenga señalada'
      ImageIndex = 15
      OnExecute = borraobsExecute
    end
    object borratodasobs: TAction
      Caption = 'Borrar Renglones'
      Hint = 'Borra todas las observaciones de la pestaña seleccionada'
      ImageIndex = 17
      OnExecute = borratodasobsExecute
    end
    object modifren: TAction
      Caption = 'Modifica Renglon'
      ImageIndex = 1
      OnExecute = modifrenExecute
    end
  end
  object qry_obslinmds: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select linea, conse, obser, fonini, fonfin, moe, cia'
      
        'from obslin where linea = :LINEA and cia = :CIA and moe = '#39'M'#39' or' +
        'der by conse'
      ' ')
    UpdateObject = uqry_obslinmds
    Left = 376
    Top = 192
    ParamData = <
      item
        DataType = ftString
        Name = 'LINEA'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_obslinmds: TDataSource
    DataSet = qry_obslinmds
    Left = 376
    Top = 226
  end
  object qry_obslinelec: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select linea, conse, obser, fonini, fonfin, moe, cia'
      
        'from obslin where linea = :LINEA and cia = :CIA and moe = '#39'E'#39' or' +
        'der by conse'
      '')
    UpdateObject = uqry_obslinelec
    Left = 408
    Top = 192
    ParamData = <
      item
        DataType = ftString
        Name = 'LINEA'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_obslinelec: TDataSource
    DataSet = qry_obslinelec
    Left = 408
    Top = 226
  end
  object uqry_obslinmds: TUpdateSQL
    ModifySQL.Strings = (
      'update obslin'
      'set'
      '  CONSE = :CONSE,'
      '  OBSER = :OBSER,'
      '  FONINI = :FONINI,'
      '  FONFIN = :FONFIN,'
      '  MOE = :MOE'
      'where'
      '  LINEA = :OLD_LINEA and'
      '  CONSE = :OLD_CONSE and'
      '  MOE = :OLD_MOE and'
      '  CIA = :OLD_CIA')
    InsertSQL.Strings = (
      'insert into obslin'
      '  (LINEA, CONSE, OBSER, FONINI, FONFIN, MOE, CIA)'
      'values'
      '  (:LINEA, :CONSE, :OBSER, :FONINI, :FONFIN, :MOE, :CIA)')
    DeleteSQL.Strings = (
      'delete from obslin'
      'where'
      '  LINEA = :OLD_LINEA and'
      '  CONSE = :OLD_CONSE and'
      '  MOE = :OLD_MOE and'
      '  CIA = :OLD_CIA')
    Left = 375
    Top = 164
  end
  object uqry_obslinelec: TUpdateSQL
    ModifySQL.Strings = (
      'update obslin'
      'set'
      '  CONSE = :CONSE,'
      '  OBSER = :OBSER,'
      '  FONINI = :FONINI,'
      '  FONFIN = :FONFIN,'
      '  MOE = :MOE'
      'where'
      '  LINEA = :OLD_LINEA and'
      '  CONSE = :OLD_CONSE and'
      '  MOE = :OLD_MOE and'
      '  CIA = :OLD_CIA')
    InsertSQL.Strings = (
      'insert into obslin'
      '  (LINEA, CONSE, OBSER, FONINI, FONFIN, MOE, CIA)'
      'values'
      '  (:LINEA, :CONSE, :OBSER, :FONINI, :FONFIN, :MOE, :CIA)')
    DeleteSQL.Strings = (
      'delete from obslin'
      'where'
      '  LINEA = :OLD_LINEA and'
      '  CONSE = :OLD_CONSE and'
      '  MOE = :OLD_MOE and'
      '  CIA = :OLD_CIA')
    Left = 407
    Top = 164
  end
  object dts_fonini: TDataSource
    Left = 281
    Top = 93
  end
  object dts_fonfin: TDataSource
    Left = 312
    Top = 93
  end
  object dts_lineas: TDataSource
    DataSet = qry_lineas
    Left = 344
    Top = 221
  end
  object qry_busconse: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select  count(*) as cuantos from obslin where linea = :LINEA'
      'and moe = :MOE and conse = :CONSE and cia = :CIA'
      ' ')
    Left = 445
    Top = 159
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'LINEA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'MOE'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CONSE'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
end

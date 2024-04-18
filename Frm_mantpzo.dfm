object Form_mantpzo: TForm_mantpzo
  Left = 213
  Top = 242
  Width = 736
  Height = 319
  Caption = 'Mantenimiento Plazos Lista Precios'
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
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 720
    Height = 54
    ButtonHeight = 49
    ButtonWidth = 24
    Caption = 'ToolBar1'
    Images = dm.ImageList1
    TabOrder = 0
    object SpeedButton5: TSpeedButton
      Left = 0
      Top = 2
      Width = 49
      Height = 49
      Action = nuevo
      Glyph.Data = {
        36040000424D3604000000000000360000002800000010000000100000000100
        2000000000000004000000000000000000000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF0000FFFF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF0000FFFF00FF00FF0000FF
        FF0000FFFF00FF00FF007B7B7B007B7B7B007B7B7B0000FFFF0000FFFF007B7B
        7B007B7B7B007B7B7B007B7B7B0000FFFF0000FFFF00FF00FF00FF00FF00FF00
        FF0000FFFF000000000000000000000000000000000000000000000000000000
        000000000000000000000000000000FFFF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00000000007B7B7B00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00000000007B7B7B00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00000000007B7B7B00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00000000007B7B7B00FF00FF00FF00FF0000FFFF0000FF
        FF0000FFFF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF000000000000FFFF0000FFFF00FF00FF00FF00FF0000FF
        FF0000FFFF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF000000000000FFFF0000FFFF0000FFFF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
        0000000000000000000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FFFF
        FF00FFFFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FFFF
        FF000000000000FFFF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
        0000FF00FF0000FFFF0000FFFF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF0000FFFF00000000000000000000000000000000000000000000000000FF00
        FF00FF00FF00FF00FF0000FFFF0000FFFF00FF00FF00FF00FF00FF00FF0000FF
        FF0000FFFF00FF00FF00FF00FF00FF00FF00FF00FF0000FFFF0000FFFF00FF00
        FF00FF00FF00FF00FF00FF00FF0000FFFF0000FFFF00FF00FF0000FFFF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF0000FFFF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF0000FFFF00}
      Layout = blGlyphTop
    end
    object SpeedButton4: TSpeedButton
      Left = 49
      Top = 2
      Width = 49
      Height = 49
      Action = modifica
      Glyph.Data = {
        36040000424D3604000000000000360000002800000010000000100000000100
        2000000000000004000000000000000000000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF0000000000FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000000000000000
        0000FF00FF000000000000000000000000000000000000000000FFFFFF00FFFF
        FF0000000000FFFFFF000000000000000000FFFFFF0000000000FFFF00000000
        00000000000000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF0000000000FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FFFF00000000
        000000FFFF00FFFFFF0000FFFF00FFFFFF00000000000000000000000000FFFF
        FF00FFFFFF00FFFFFF00FFFFFF0000000000FFFFFF0000000000FFFF00000000
        0000FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF000000
        0000FFFFFF000000000000000000FFFFFF00FFFFFF0000000000FFFF00000000
        000000FFFF00FFFFFF0000FFFF00FFFFFF000000000000000000000000000000
        00000000000000FFFF0000000000FFFFFF00FFFFFF0000000000FFFF00000000
        0000FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FF
        FF00FFFFFF0000000000FFFFFF00FFFFFF00FFFFFF0000000000FFFF00000000
        000000FFFF00FFFFFF0000000000000000000000000000000000000000000000
        000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000000000000000
        00000000000000FFFF00FFFFFF0000FFFF00000000000000000000FFFF000000
        0000FFFFFF00FFFFFF000000000000000000FFFFFF0000000000FF00FF00FF00
        FF00FF00FF000000000000000000000000000000000000FFFF0000000000FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF000000000000FFFF0000000000FFFFFF00FFFF
        FF00FFFFFF00FFFFFF0000000000000000000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF000000000000FFFF0000000000FFFFFF00FFFFFF000000
        000000000000FFFFFF0000000000FFFFFF00FFFFFF0000000000FF00FF00FF00
        FF00FF00FF000000000000FFFF000000000000000000FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF0000000000FFFFFF0000000000FF00FF00FF00FF00FF00
        FF00000000000000FF0000000000FF00FF0000000000FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF000000000000000000FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FF00FF00FF00FF000000000000000000000000000000
        0000000000000000000000000000FF00FF00FF00FF00FF00FF00}
      Layout = blGlyphTop
    end
    object SpeedButton3: TSpeedButton
      Left = 98
      Top = 2
      Width = 49
      Height = 49
      Action = borra
      Glyph.Data = {
        36040000424D3604000000000000360000002800000010000000100000000100
        2000000000000004000000000000000000000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF007B7B7B007B7B
        7B007B7B7B007B7B7B007B7B7B007B7B7B007B7B7B00FF00FF007B7B7B00FF00
        FF00FF00FF000000FF000000FF000000FF00FF00FF007B7B7B00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00000000000084840000000000FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00
        FF00FF00FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF0000000000FFFFFF0000FFFF000000
        000000000000000000000000000000000000FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF0000000000FFFFFF0000FFFF000000000000FF
        FF00FFFFFF0000000000FFFFFF0000000000FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF0000000000FFFFFF0000FFFF00FFFFFF0000FFFF00FFFF
        FF0000000000FFFFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF000000000000FFFF00FFFFFF0000FFFF00FFFFFF000000
        0000FFFFFF0000FFFF000000000000000000FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF000000000000000000FFFFFF0000FFFF00FFFFFF0000FFFF00FFFF
        FF0000FFFF000000000000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00
        FF0000000000FFFF00000000000000FFFF00FFFFFF0000FFFF00FFFFFF0000FF
        FF00000000000000000000FFFF0000000000FF00FF00FF00FF00FF00FF000000
        0000FFFF0000FFFF0000FFFF00000000000000FFFF00FFFFFF0000FFFF000000
        000000FFFF000000000000FFFF0000000000FF00FF00FF00FF00000000000000
        000000000000FFFF0000FFFF0000FFFF00000000000000FFFF00FFFFFF0000FF
        FF00FFFFFF000000000000FFFF0000000000FF00FF00FF00FF00000000000000
        00000000000000000000FFFF0000FFFF0000FFFF000000000000000000000000
        0000000000000000000000FFFF0000000000FF00FF00FF00FF00000000000000
        0000000000000000000000000000FFFF000000000000FF00FF00FF00FF00FF00
        FF00FF00FF0000000000BDBDBD0000000000FF00FF00FF00FF00FF00FF000000
        000000000000000000000000000000000000FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00000000000000000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF0000000000FF00FF00FF00FF00FF00FF00}
      Layout = blGlyphTop
    end
    object SpeedButton2: TSpeedButton
      Left = 147
      Top = 2
      Width = 49
      Height = 49
      Action = exportar
      Glyph.Data = {
        36040000424D3604000000000000360000002800000010000000100000000100
        2000000000000004000000000000000000000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF000000FF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF000000FF000000FF0000000000FF00FF00FF00FF00FF00FF00000000000000
        0000000000000000000000000000000000000000FF000000FF000000FF000000
        FF000000FF000000FF000000FF0000000000FF00FF00FF00FF0000000000FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00000000000000FF000000FF000000FF000000
        FF000000FF000000FF000000FF000000FF0000000000FF00FF0000000000FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00000000000000FF000000FF000000FF000000
        FF000000FF000000FF000000FF000000FF000000FF000000000000000000FFFF
        FF000000000000000000FFFFFF00000000000000FF000000FF000000FF000000
        FF000000FF000000FF000000FF000000FF0000000000FF00FF0000000000FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00000000000000FF000000FF000000FF000000
        FF000000FF000000FF000000FF0000000000FF00FF00FF00FF0000000000FFFF
        FF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000
        00000000FF000000FF0000000000FF00FF00FF00FF00FF00FF0000000000FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000
        00000000FF0000000000FF00FF00FF00FF00FF00FF00FF00FF0000000000FFFF
        FF000000000000000000FFFFFF00000000000000000000000000000000000000
        000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF0000000000FFFF
        FF00FFFFFF00FFFFFF00FFFFFF0000000000FFFFFF00FFFFFF0000000000FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF0000000000FFFF
        FF0000000000BDBDBD00FFFFFF0000000000FFFFFF0000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF0000000000FFFF
        FF00FFFFFF00FFFFFF00FFFFFF000000000000000000FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
        000000000000000000000000000000000000FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00}
      Layout = blGlyphTop
    end
    object SpeedButton1: TSpeedButton
      Left = 196
      Top = 2
      Width = 49
      Height = 49
      Action = WindowClose1
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
      Layout = blGlyphTop
    end
    object ToolButton3: TToolButton
      Left = 245
      Top = 2
      Width = 8
      Caption = 'ToolButton3'
      ImageIndex = 5
      Style = tbsSeparator
    end
  end
  object pge_mayomen: TPageControl
    Left = 0
    Top = 54
    Width = 720
    Height = 226
    ActivePage = tbs_menudeo
    Align = alClient
    TabOrder = 1
    OnChange = pge_mayomenChange
    object tbs_menudeo: TTabSheet
      Caption = 'Menudeo'
      object Splitter1: TSplitter
        Left = 553
        Top = 0
        Width = 3
        Height = 198
        Cursor = crHSplit
        Align = alRight
      end
      object pge_listas: TPageControl
        Left = 0
        Top = 0
        Width = 553
        Height = 198
        ActivePage = tbs_lineas
        Align = alClient
        PopupMenu = PopupMenu1
        TabOrder = 0
        object tbs_lineas: TTabSheet
          Caption = 'Plazos x Línea'
          OnShow = tbs_lineasShow
          object dbgrd_pzolineas: TdxDBGrid
            Left = 0
            Top = 0
            Width = 545
            Height = 170
            Bands = <
              item
              end>
            DefaultLayout = True
            HeaderPanelRowCount = 1
            KeyField = 'IDPLAZOCRD'
            SummaryGroups = <>
            SummarySeparator = ', '
            Align = alClient
            TabOrder = 0
            OnKeyDown = dbgrd_pzolineasKeyDown
            DataSource = dts_plazoxlinea
            Filter.Criteria = {00000000}
            OptionsDB = [edgoCancelOnExit, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoSyncSelection, edgoUseBookmarks, edgoUseLocate]
            OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
            OnCustomDrawCell = dbgrd_pzolineasCustomDrawCell
            object dbgrd_pzolineasLINEA: TdxDBGridMaskColumn
              Caption = 'Línea'
              Width = 34
              BandIndex = 0
              RowIndex = 0
              FieldName = 'LINEA'
            end
            object dbgrd_pzolineasDESCRI: TdxDBGridMaskColumn
              Caption = 'Descripción'
              Width = 215
              BandIndex = 0
              RowIndex = 0
              FieldName = 'DESCRI'
            end
            object dbgrd_pzolineasPLAZOMAX: TdxDBGridMaskColumn
              Caption = 'Plazo Máximo'
              Width = 71
              BandIndex = 0
              RowIndex = 0
              FieldName = 'PLAZOMAX'
            end
            object dbgrd_pzolineasColumn5: TdxDBGridMaskColumn
              Caption = 'Descripcion Tipo'
              BandIndex = 0
              RowIndex = 0
              FieldName = 'descritipo'
            end
            object dbgrd_pzolineasTIPO: TdxDBGridMaskColumn
              Caption = 'Tipo'
              Width = 27
              BandIndex = 0
              RowIndex = 0
              FieldName = 'cvepzo'
            end
          end
        end
        object tbs_precios: TTabSheet
          Caption = 'Plazos x Precio'
          ImageIndex = 2
          OnShow = tbs_lineasShow
          object dbgrd_plazoxprecio: TdxDBGrid
            Left = 0
            Top = 0
            Width = 545
            Height = 171
            Bands = <
              item
              end>
            DefaultLayout = True
            HeaderPanelRowCount = 1
            KeyField = 'IDPLAZOCRD'
            SummaryGroups = <>
            SummarySeparator = ', '
            Align = alClient
            TabOrder = 0
            OnKeyDown = dbgrd_pzolineasKeyDown
            DataSource = dts_plazoxprecio
            Filter.Criteria = {00000000}
            OptionsDB = [edgoCancelOnExit, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoSyncSelection, edgoUseBookmarks, edgoUseLocate]
            OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
            OnCustomDrawCell = dbgrd_pzolineasCustomDrawCell
            object dxDBGridPLAZOMAX: TdxDBGridMaskColumn
              Caption = 'Plazo Máximo'
              Width = 71
              BandIndex = 0
              RowIndex = 0
              FieldName = 'PLAZOMAX'
            end
            object dxDBGridCurrencyPLISTAMAX: TdxDBGridCurrencyColumn
              Caption = 'P.Lista.Máximo'
              Width = 76
              BandIndex = 0
              RowIndex = 0
              FieldName = 'PLISTAMAX'
            end
            object dxDBGridTIPO: TdxDBGridMaskColumn
              Caption = 'Tipo'
              Visible = False
              Width = 27
              BandIndex = 0
              RowIndex = 0
              FieldName = 'TIPO'
            end
          end
        end
        object tbs_grupos: TTabSheet
          Caption = 'Plazos x Grupo'
          ImageIndex = 3
          OnShow = tbs_lineasShow
          object dbgrd_plazoxgpo: TdxDBGrid
            Left = 0
            Top = 0
            Width = 545
            Height = 170
            Bands = <
              item
              end>
            DefaultLayout = True
            HeaderPanelRowCount = 1
            KeyField = 'IDPLAZOCRD'
            SummaryGroups = <>
            SummarySeparator = ', '
            Align = alClient
            PopupMenu = PopupMenu1
            TabOrder = 0
            OnKeyDown = dbgrd_pzolineasKeyDown
            DataSource = dts_plazoxgrupo
            Filter.Criteria = {00000000}
            OptionsDB = [edgoCancelOnExit, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoSyncSelection, edgoUseBookmarks, edgoUseLocate]
            OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
            OnCustomDrawCell = dbgrd_pzolineasCustomDrawCell
            object dbgrd_plazoxgpoLinea: TdxDBGridMaskColumn
              Caption = 'Línea'
              BandIndex = 0
              RowIndex = 0
              FieldName = 'linea'
            end
            object dxDBGridMaskColumn5: TdxDBGridMaskColumn
              Caption = 'Código'
              Width = 89
              BandIndex = 0
              RowIndex = 0
              FieldName = 'CODIGO'
            end
            object dxDBGridMaskColumn6: TdxDBGridMaskColumn
              Caption = 'Descripción'
              Width = 245
              BandIndex = 0
              RowIndex = 0
              FieldName = 'DESCRI'
            end
            object dxDBGridMaskColumn9: TdxDBGridMaskColumn
              Alignment = taLeftJustify
              Caption = 'Plazo Máximo'
              Width = 81
              BandIndex = 0
              RowIndex = 0
              FieldName = 'PLAZOMAX'
            end
            object dxDBGridMaskColumn10: TdxDBGridMaskColumn
              Caption = 'Tipo'
              Width = 30
              BandIndex = 0
              RowIndex = 0
              FieldName = 'cvepzo'
            end
            object dbgrd_plazoxgpoColumn6: TdxDBGridMaskColumn
              Caption = 'Descripción Tipo'
              BandIndex = 0
              RowIndex = 0
              FieldName = 'descritipo'
            end
          end
        end
        object tbs_articulos: TTabSheet
          Caption = 'Plazos x Artículos'
          ImageIndex = 1
          OnShow = tbs_lineasShow
          object dbgrd_pzoartic: TdxDBGrid
            Left = 0
            Top = 0
            Width = 545
            Height = 170
            Bands = <
              item
              end>
            DefaultLayout = True
            HeaderPanelRowCount = 1
            KeyField = 'IDPLAZOCRD'
            SummaryGroups = <>
            SummarySeparator = ', '
            Align = alClient
            PopupMenu = PopupMenu1
            TabOrder = 0
            OnKeyDown = dbgrd_pzolineasKeyDown
            DataSource = dts_preciosart
            Filter.Criteria = {00000000}
            OptionsDB = [edgoCancelOnExit, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoSyncSelection, edgoUseBookmarks, edgoUseLocate]
            OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
            OnCustomDrawCell = dbgrd_pzolineasCustomDrawCell
            object dxDBGridMaskColumn1: TdxDBGridMaskColumn
              Caption = 'Código'
              Width = 89
              BandIndex = 0
              RowIndex = 0
              FieldName = 'CODIGO'
            end
            object dxDBGridMaskColumn2: TdxDBGridMaskColumn
              Caption = 'Descripción'
              Width = 245
              BandIndex = 0
              RowIndex = 0
              FieldName = 'DESCRI'
            end
            object dxDBGridMaskColumn3: TdxDBGridMaskColumn
              Caption = 'Plazo Máximo'
              Width = 81
              BandIndex = 0
              RowIndex = 0
              FieldName = 'PLAZOMAX'
            end
            object dxDBGridMaskColumn4: TdxDBGridMaskColumn
              Caption = 'Tipo'
              Visible = False
              Width = 30
              BandIndex = 0
              RowIndex = 0
              FieldName = 'TIPO'
            end
          end
        end
      end
      object mmo_instruc: TMemo
        Left = 556
        Top = 0
        Width = 156
        Height = 198
        Align = alRight
        Lines.Strings = (
          'El plazo máximo se'
          'establece por'
          'líneas, Si se quiere el mismo '
          'plazo'
          'máximo para toda la línea  '
          'se usa'
          'tipo 1'
          'Para tener diferentes plazos '
          'máximos'
          'en una línea se utilizará:'
          'Tipo 2 para establecer '
          'según tabla'
          'de precios'
          'Tipo 3 para establecer '
          'segun grupos'
          'de la línea; los grupos a si '
          'vez'
          'pueden ser tipo 1 o 2'
          'Tipo 4 para establecer por'
          'artículos '
          'específicos'
          ''
          'El plazo primero se busca '
          'por Linea,'
          'luego por Precio, luego por '
          'Articulo'
          ' Luego x Linea Prioridad '
          'Luego x '
          'Grupo Luego x Grupo '
          'Prioridad'
          ' Si hay plazo x articulo se '
          'toma ese y '
          'listo.'
          ' Si hay plazo x Grupo '
          'Prioridad se '
          'toma ese y listo'
          ' Si hay plazo x Linea'
          'Prioridad se '
          'toma el plazo x Linea '
          'prioridad'
          ' Si hay plazo Linea se '
          'compara con '
          'el plazo x Precio y se toma '
          'el menor'
          ' Si hay plazo x grupo se '
          'compara '
          'con el resultado anterior y '
          'se toma el '
          'menor'
          ''
          'Definición de Tipos'
          '(PLAZO_X_LINEA)=(1);'
          '(PLAZO_X_PRECIO)=(2);'
          '(PLAZO_X_ARTICULO)=(3)'
          ';'
          '(PLAZO_LINEA_PRIORIDA'
          'D)=(4);'
          '(PLAZO_X_GRUPO_PRIO'
          'RIDAD)=('
          '5);'
          '(PLAZO_X_GRUPO)=(6);'
          ''
          ' '
          ' ')
        ScrollBars = ssVertical
        TabOrder = 1
      end
    end
    object tbs_mayoreo: TTabSheet
      Caption = 'Mayoreo'
      ImageIndex = 1
      object Splitter2: TSplitter
        Left = 553
        Top = 0
        Width = 3
        Height = 198
        Cursor = crHSplit
        Align = alRight
      end
      object pge_mayoreo: TPageControl
        Left = 0
        Top = 0
        Width = 553
        Height = 198
        ActivePage = tbs_gpomayoreo
        Align = alClient
        TabOrder = 0
        object tbs_gpomayoreo: TTabSheet
          Caption = 'Promo Mayoreo Grupo'
          OnShow = tbs_lineasShow
          object dbgrd_gpomayprecio: TdxDBGrid
            Left = 0
            Top = 0
            Width = 545
            Height = 171
            Bands = <
              item
              end>
            DefaultLayout = True
            HeaderPanelRowCount = 1
            KeyField = 'IDGPOMAYPRECIO'
            SummaryGroups = <>
            SummarySeparator = ', '
            Align = alClient
            PopupMenu = PopupMenu1
            TabOrder = 0
            OnKeyDown = dbgrd_pzolineasKeyDown
            DataSource = dts_invgpomayprecio
            Filter.Criteria = {00000000}
            OptionsDB = [edgoCancelOnExit, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoSyncSelection, edgoUseBookmarks, edgoUseLocate]
            OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
            OnCustomDrawCell = dbgrd_pzolineasCustomDrawCell
            object dbgrd_gpomayprecioCODIGO: TdxDBGridMaskColumn
              Caption = 'Código'
              Width = 89
              BandIndex = 0
              RowIndex = 0
              FieldName = 'CODIGO'
            end
            object dbgrd_gpomayprecioDESCRI: TdxDBGridMaskColumn
              Caption = 'Descripción'
              Width = 245
              BandIndex = 0
              RowIndex = 0
              FieldName = 'DESCRI'
            end
            object dbgrd_gpomayprecioFACTORPRECIO: TdxDBGridCurrencyColumn
              Caption = 'Factor Precio'
              Width = 81
              BandIndex = 0
              RowIndex = 0
              FieldName = 'FACTORPRECIO'
              DecimalPlaces = 4
              DisplayFormat = ',0.0000;-,0.0000'
            end
            object dbgrd_gpomayprecioFECHA: TdxDBGridMaskColumn
              Caption = 'Fecha'
              BandIndex = 0
              RowIndex = 0
              FieldName = 'FECHA'
            end
            object dbgrd_gpomayprecioTIPO: TdxDBGridMaskColumn
              Caption = 'Tipo'
              Width = 30
              BandIndex = 0
              RowIndex = 0
              FieldName = 'TIPO'
            end
          end
        end
        object tbs_preciomaypro: TTabSheet
          Caption = 'Precio x Mayorista'
          ImageIndex = 1
          OnShow = tbs_lineasShow
          object dbgrd_preciomaypro: TdxDBGrid
            Left = 0
            Top = 0
            Width = 545
            Height = 171
            Bands = <
              item
              end>
            DefaultLayout = True
            HeaderPanelRowCount = 1
            KeyField = 'idplazocrd'
            SummaryGroups = <>
            SummarySeparator = ', '
            Align = alClient
            TabOrder = 0
            OnKeyDown = dbgrd_pzolineasKeyDown
            DataSource = dts_precioxprove
            Filter.Criteria = {00000000}
            OptionsDB = [edgoCancelOnExit, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoSyncSelection, edgoUseBookmarks, edgoUseLocate]
            OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
            OnCustomDrawCell = dbgrd_pzolineasCustomDrawCell
            object dxDBGridMaskColumn11: TdxDBGridMaskColumn
              Caption = 'Código'
              Width = 89
              BandIndex = 0
              RowIndex = 0
              FieldName = 'prove'
            end
            object dxDBGridMaskColumn12: TdxDBGridMaskColumn
              Caption = 'Nombre'
              Width = 245
              BandIndex = 0
              RowIndex = 0
              FieldName = 'nombre'
            end
            object dxDBGridCurrencyColumn2: TdxDBGridCurrencyColumn
              Caption = 'Factor Precio'
              Width = 81
              BandIndex = 0
              RowIndex = 0
              FieldName = 'FACTOR'
              DecimalPlaces = 4
              DisplayFormat = ',0.0000;-,0.0000'
            end
            object dxDBGridMaskColumn14: TdxDBGridMaskColumn
              Caption = 'Tipo'
              Width = 30
              BandIndex = 0
              RowIndex = 0
              FieldName = 'TIPO'
            end
          end
        end
      end
      object mmo_observsmay: TMemo
        Left = 556
        Top = 0
        Width = 156
        Height = 198
        Align = alRight
        ScrollBars = ssVertical
        TabOrder = 1
      end
    end
  end
  object qry_plazoscrd: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select idplazocrd, a.idlinea, a.linea, plazomax, plistamax, a.ti' +
        'po, a.cia'
      'from plazoscrd a '
      'where a.cia = :CIA '
      'order by a.tipo, a.plazomax')
    UpdateObject = uqry_plazoscrd
    Left = 315
    Top = 175
    ParamData = <
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object uqry_plazoscrd: TUpdateSQL
    ModifySQL.Strings = (
      'update plazoscrd'
      'set'
      '  IDPLAZOCRD = :IDPLAZOCRD,'
      '  IDLINEA = :IDLINEA,'
      '  LINEA = :LINEA,'
      '  PLAZOMAX = :PLAZOMAX,'
      '  PLISTAMAX = :PLISTAMAX,'
      '  TIPO = :TIPO,'
      '  CIA = :CIA'
      'where'
      '  IDPLAZOCRD = :OLD_IDPLAZOCRD')
    InsertSQL.Strings = (
      'insert into plazoscrd'
      '  (IDPLAZOCRD, IDLINEA, LINEA, PLAZOMAX, PLISTAMAX, TIPO, CIA)'
      'values'
      
        '  (:IDPLAZOCRD, :IDLINEA, :LINEA, :PLAZOMAX, :PLISTAMAX, :TIPO, ' +
        ':CIA)')
    DeleteSQL.Strings = (
      'delete from plazoscrd'
      'where'
      '  IDPLAZOCRD = :OLD_IDPLAZOCRD')
    Left = 345
    Top = 175
  end
  object ActionList1: TActionList
    Images = dm.ImageList1
    Left = 283
    Top = 175
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
      Caption = '&Borra'
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
      OnExecute = grabarExecute
    end
    object cancelar: TAction
      Caption = 'Cancelar'
      Enabled = False
      ImageIndex = 11
      ShortCut = 16460
    end
    object WindowClose1: TWindowClose
      Category = 'Window'
      Caption = '&Salir'
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
    object exportar: TAction
      Caption = 'Expotar a...'
      ImageIndex = 19
      OnExecute = exportarExecute
    end
  end
  object dts_plazoscrd: TDataSource
    AutoEdit = False
    DataSet = qry_plazoscrd
    Left = 377
    Top = 175
  end
  object qry_preciosart: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select idplazocrd, a.idlinea, a.linea, plazomax, plistamax, a.ti' +
        'po, a.cia,'
      'c.codigo, c.descri'
      'from plazoscrd a join inv_invhist b on a.idlinea = b.idart'
      'join inven c on b.codigo = c.codigo and b.cia = c.cia'
      'where '
      'a.cia = :CIA and a.tipo = :TIPOART '
      'order by a.tipo, c.codigo, a.plazomax'
      ' ')
    Left = 315
    Top = 207
    ParamData = <
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'TIPOART'
        ParamType = ptUnknown
      end>
  end
  object dts_preciosart: TDataSource
    AutoEdit = False
    DataSet = qry_preciosart
    Left = 349
    Top = 207
  end
  object qry_plazoxgrupo: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select idplazocrd, a.idlinea, a.linea, plazomax, plistamax, a.ti' +
        'po, a.cia,'
      'b.codigo, b.descri, c.cvepzo, c.descri as descritipo'
      'from plazoscrd a join inv_grupos b on a.idlinea = b.idgrupo'
      'join inv_plazoslispre c on a.tipo = c.idplazo'
      'where'
      'a.cia = :CIA and c.tipolista = :TIPO1'
      'order by b.codigo, a.plazomax'
      '')
    Left = 315
    Top = 239
    ParamData = <
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'TIPO1'
        ParamType = ptUnknown
      end>
  end
  object dts_plazoxgrupo: TDataSource
    AutoEdit = False
    DataSet = qry_plazoxgrupo
    Left = 350
    Top = 239
  end
  object qry_plazoxprecio: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select idplazocrd, a.idlinea, plazomax, plistamax, a.tipo, a.cia'
      'from plazoscrd a'
      'where a.cia = :CIA and  a.tipo = :TIPO1'
      'order by a.tipo, a.plazomax')
    Left = 314
    Top = 143
    ParamData = <
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'TIPO1'
        ParamType = ptUnknown
      end>
  end
  object dts_plazoxprecio: TDataSource
    AutoEdit = False
    DataSet = qry_plazoxprecio
    Left = 345
    Top = 143
  end
  object qry_plazoxlinea: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select idplazocrd, a.idlinea, a.linea, plazomax, plistamax, a.ti' +
        'po, a.cia,'
      'b.orden, b.descri, c.cvepzo, c.descri as descritipo'
      'from plazoscrd a'
      'join inv_lineas b on a.idlinea = b.idlinea'
      'join inv_plazoslispre c on a.tipo = c.idplazo'
      'where a.cia = :CIA and c.tipolista = :TIPO1'
      ''
      'order by b.orden, a.linea, a.tipo, a.plazomax'
      ''
      ' ')
    Left = 314
    Top = 113
    ParamData = <
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'TIPO1'
        ParamType = ptUnknown
      end>
  end
  object dts_plazoxlinea: TDataSource
    AutoEdit = False
    DataSet = qry_plazoxlinea
    Left = 344
    Top = 113
  end
  object qry_invgpomayprecio: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select'
      'idgpomayprecio, a.idgrupo, factorprecio, fecha, fechora, a.cia,'
      'tipo, b.codigo, b.descri'
      'from inv_gpomayprecio a'
      'join inv_grupos b on a.idgrupo = b.idgrupo'
      'where a.cia = :CIA'
      'order by b.codigo'
      '')
    UpdateObject = uqry_invgpomayprecio
    Left = 27
    Top = 103
    ParamData = <
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object uqry_invgpomayprecio: TUpdateSQL
    ModifySQL.Strings = (
      'update inv_gpomayprecio'
      'set'
      '  IDGPOMAYPRECIO = :IDGPOMAYPRECIO,'
      '  IDGRUPO = :IDGRUPO,'
      '  FACTORPRECIO = :FACTORPRECIO,'
      '  FECHA = :FECHA,'
      '  FECHORA = :FECHORA,'
      '  CIA = :CIA,'
      '  TIPO = :TIPO'
      'where'
      '  IDGPOMAYPRECIO = :OLD_IDGPOMAYPRECIO')
    InsertSQL.Strings = (
      'insert into inv_gpomayprecio'
      
        '  (IDGPOMAYPRECIO, IDGRUPO, FACTORPRECIO, FECHA, FECHORA, CIA, T' +
        'IPO)'
      'values'
      
        '  (:IDGPOMAYPRECIO, :IDGRUPO, :FACTORPRECIO, :FECHA, :FECHORA, :' +
        'CIA, '
      ':TIPO)')
    DeleteSQL.Strings = (
      'delete from inv_gpomayprecio'
      'where'
      '  IDGPOMAYPRECIO = :OLD_IDGPOMAYPRECIO')
    Left = 57
    Top = 103
  end
  object dts_invgpomayprecio: TDataSource
    AutoEdit = False
    DataSet = qry_invgpomayprecio
    Left = 89
    Top = 103
  end
  object qry_precioxprove: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select idplazocrd, a.linea as prove, a.idlinea, plistamax as fac' +
        'tor, a.tipo, a.cia, b.nombre'
      'from plazoscrd a '
      'join proveedor b on a.linea = b.codigo and a.cia = b.cia'
      'where a.cia = :CIA and  a.tipo = :TIPO'
      'order by a.tipo, a.linea'
      ''
      ' ')
    UpdateObject = uqry_precioxprove
    Left = 27
    Top = 135
    ParamData = <
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'TIPO'
        ParamType = ptUnknown
      end>
  end
  object uqry_precioxprove: TUpdateSQL
    ModifySQL.Strings = (
      'update inv_gpomayprecio'
      'set'
      '  IDGPOMAYPRECIO = :IDGPOMAYPRECIO,'
      '  IDGRUPO = :IDGRUPO,'
      '  FACTORPRECIO = :FACTORPRECIO,'
      '  FECHA = :FECHA,'
      '  FECHORA = :FECHORA,'
      '  CIA = :CIA,'
      '  TIPO = :TIPO'
      'where'
      '  IDGPOMAYPRECIO = :OLD_IDGPOMAYPRECIO')
    InsertSQL.Strings = (
      'insert into inv_gpomayprecio'
      
        '  (IDGPOMAYPRECIO, IDGRUPO, FACTORPRECIO, FECHA, FECHORA, CIA, T' +
        'IPO)'
      'values'
      
        '  (:IDGPOMAYPRECIO, :IDGRUPO, :FACTORPRECIO, :FECHA, :FECHORA, :' +
        'CIA, '
      ':TIPO)')
    DeleteSQL.Strings = (
      'delete from inv_gpomayprecio'
      'where'
      '  IDGPOMAYPRECIO = :OLD_IDGPOMAYPRECIO')
    Left = 57
    Top = 135
  end
  object dts_precioxprove: TDataSource
    AutoEdit = False
    DataSet = qry_precioxprove
    Left = 89
    Top = 135
  end
  object PopupMenu1: TPopupMenu
    Left = 216
    Top = 184
    object Nuevo1: TMenuItem
      Action = nuevo
    end
    object Borra1: TMenuItem
      Action = borra
    end
    object Modifica1: TMenuItem
      Action = modifica
    end
    object Expotara1: TMenuItem
      Action = exportar
    end
  end
end
